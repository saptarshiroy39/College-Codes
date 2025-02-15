#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <limits>

using namespace std;

// Date utility class to handle loan dates and calculations
class Date
{
private:
  int day, month, year;

public:
  Date()
  {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    day = ltm->tm_mday;
    month = 1 + ltm->tm_mon;
    year = 1900 + ltm->tm_year;
  }

  Date(int d, int m, int y) : day(d), month(m), year(y) {}

  void addDays(int days)
  {
    day += days;
    if (day > 30)
    {
      month += day / 30;
      day = day % 30;
    }
    if (month > 12)
    {
      year += month / 12;
      month = month % 12;
    }
  }

  int daysDifference(const Date &other) const
  {
    int thisDays = year * 365 + month * 30 + day;
    int otherDays = other.year * 365 + other.month * 30 + other.day;
    return thisDays - otherDays;
  }

  string toString() const
  {
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
  }
};

class Book
{
private:
  int id;
  string title;
  string author;
  string genre;
  int publicationYear;
  bool isAvailable;
  int currentBorrowerId;

public:
  Book(int id, string title, string author, string genre, int year)
      : id(id), title(title), author(author), genre(genre),
        publicationYear(year), isAvailable(true), currentBorrowerId(-1) {}

  int getId() const { return id; }
  string getTitle() const { return title; }
  string getAuthor() const { return author; }
  string getGenre() const { return genre; }
  bool getAvailability() const { return isAvailable; }
  int getCurrentBorrowerId() const { return currentBorrowerId; }

  void setAvailability(bool status) { isAvailable = status; }
  void setBorrower(int memberId) { currentBorrowerId = memberId; }

  string toString() const
  {
    return "\nID: " + to_string(id) + "\nTitle: " + title +
           "\nAuthor: " + author + "\nGenre: " + genre +
           "\nYear: " + to_string(publicationYear) +
           "\nAvailable: " + (isAvailable ? "Yes" : "No");
  }
};

class Loan
{
private:
  int bookId;
  int memberId;
  Date borrowDate;
  Date dueDate;
  bool isReturned;

public:
  Loan(int bookId, int memberId)
      : bookId(bookId), memberId(memberId), borrowDate(), isReturned(false)
  {
    dueDate = borrowDate;
    dueDate.addDays(14);
  }

  int getBookId() const { return bookId; }
  int getMemberId() const { return memberId; }
  Date getDueDate() const { return dueDate; }
  bool getReturnStatus() const { return isReturned; }
  void setReturned() { isReturned = true; }

  int calculateFine() const
  {
    if (isReturned)
      return 0;

    Date currentDate;
    int daysOverdue = currentDate.daysDifference(dueDate);
    return daysOverdue > 0 ? daysOverdue * 5 : 0;
  }
};

class Member
{
private:
  int memberId;
  string name;
  string address;
  string contactInfo;
  vector<int> borrowedBooks;

public:
  Member(int id, string name, string address, string contact)
      : memberId(id), name(name), address(address), contactInfo(contact) {}

  int getId() const { return memberId; }
  string getName() const { return name; }
  const vector<int> &getBorrowedBooks() const { return borrowedBooks; }

  void borrowBook(int bookId)
  {
    borrowedBooks.push_back(bookId);
  }

  void returnBook(int bookId)
  {
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), bookId);
    if (it != borrowedBooks.end())
    {
      borrowedBooks.erase(it);
    }
  }

  string toString() const
  {
    return "ID: " + to_string(memberId) + ", Name: " + name +
           ", Contact: " + contactInfo;
  }
};

class LibrarySystem
{
private:
  vector<Book> books;
  vector<Member> members;
  vector<Loan> loans;
  int nextBookId;
  int nextMemberId;

  void saveToFile()
  {
    ofstream bookFile("books.txt");
    for (const auto &book : books)
    {
      bookFile << book.toString() << endl;
    }
    bookFile.close();

    ofstream memberFile("members.txt");
    for (const auto &member : members)
    {
      memberFile << member.toString() << endl;
    }
    memberFile.close();
  }

public:
  LibrarySystem() : nextBookId(1), nextMemberId(1) {}

  void addBook(string title, string author, string genre, int year)
  {
    books.emplace_back(nextBookId++, title, author, genre, year);
    saveToFile();
    cout << "Book added successfully.\n";
  }

  void removeBook(int bookId)
  {
    auto it = find_if(books.begin(), books.end(),
                      [bookId](const Book &book)
                      { return book.getId() == bookId; });

    if (it != books.end())
    {
      books.erase(it);
      saveToFile();
      cout << "Book removed successfully.\n";
    }
    else
    {
      cout << "Book not found.\n";
    }
  }

  void registerMember(string name, string address, string contact)
  {
    members.emplace_back(nextMemberId++, name, address, contact);
    saveToFile();
    cout << "Member registered successfully.\n";
  }

  void removeMember(int memberId)
  {
    auto it = find_if(members.begin(), members.end(),
                      [memberId](const Member &member)
                      { return member.getId() == memberId; });

    if (it != members.end())
    {
      members.erase(it);
      saveToFile();
      cout << "Member removed successfully.\n";
    }
    else
    {
      cout << "Member not found.\n";
    }
  }

  void borrowBook(int memberId, int bookId)
  {
    auto book = find_if(books.begin(), books.end(),
                        [bookId](const Book &b)
                        { return b.getId() == bookId; });

    auto member = find_if(members.begin(), members.end(),
                          [memberId](const Member &m)
                          { return m.getId() == memberId; });

    if (book != books.end() && member != members.end())
    {
      if (book->getAvailability())
      {
        book->setAvailability(false);
        book->setBorrower(memberId);
        member->borrowBook(bookId);
        loans.emplace_back(bookId, memberId);
        saveToFile();
        cout << "Book borrowed successfully.\n";
      }
      else
      {
        cout << "Book is not available.\n";
      }
    }
    else
    {
      cout << "Book or member not found.\n";
    }
  }

  void returnBook(int memberId, int bookId)
  {
    auto book = find_if(books.begin(), books.end(),
                        [bookId](const Book &b)
                        { return b.getId() == bookId; });

    auto member = find_if(members.begin(), members.end(),
                          [memberId](const Member &m)
                          { return m.getId() == memberId; });

    auto loan = find_if(loans.begin(), loans.end(),
                        [bookId, memberId](const Loan &l)
                        {
                          return l.getBookId() == bookId &&
                                 l.getMemberId() == memberId &&
                                 !l.getReturnStatus();
                        });

    if (book != books.end() && member != members.end() && loan != loans.end())
    {
      int fine = loan->calculateFine();
      if (fine > 0)
      {
        cout << "Fine due: Rs " << fine << endl;
      }

      book->setAvailability(true);
      book->setBorrower(-1);
      member->returnBook(bookId);
      loan->setReturned();
      saveToFile();
      cout << "Book returned successfully.\n";
    }
    else
    {
      cout << "Return failed. Please check book and member IDs.\n";
    }
  }

  void searchBooks(string query)
  {
    cout << "\nSearch Results:\n";
    bool found = false;
    for (const auto &book : books)
    {
      if (book.getTitle().find(query) != string::npos ||
          book.getAuthor().find(query) != string::npos ||
          book.getGenre().find(query) != string::npos)
      {
        cout << book.toString() << endl;
        found = true;
      }
    }
    if (!found)
    {
      cout << "No books found matching your search.\n";
    }
  }

  void showOverdueList()
  {
    cout << "\nOverdue Books:\n";
    bool hasOverdue = false;
    for (const auto &loan : loans)
    {
      if (!loan.getReturnStatus() && loan.calculateFine() > 0)
      {
        auto book = find_if(books.begin(), books.end(),
                            [&loan](const Book &b)
                            { return b.getId() == loan.getBookId(); });

        auto member = find_if(members.begin(), members.end(),
                              [&loan](const Member &m)
                              { return m.getId() == loan.getMemberId(); });

        if (book != books.end() && member != members.end())
        {
          cout << "Book: " << book->getTitle()
               << ", Member: " << member->getName()
               << ", Fine: Rs " << loan.calculateFine()
               << ", Due Date: " << loan.getDueDate().toString() << endl;
          hasOverdue = true;
        }
      }
    }
    if (!hasOverdue)
    {
      cout << "No overdue books found.\n";
    }
  }

  void generateReport()
  {
    cout << "\nCurrent Library Status Report\n";
    cout << "============================\n";

    cout << "\nTotal Books: " << books.size() << endl;
    cout << "Total Members: " << members.size() << endl;

    int borrowedBooks = 0;
    for (const auto &book : books)
    {
      if (!book.getAvailability())
        borrowedBooks++;
    }

    cout << "Books Currently Borrowed: " << borrowedBooks << endl;

    if (borrowedBooks > 0)
    {
      cout << "\nBorrowed Books Details:\n";
      for (const auto &book : books)
      {
        if (!book.getAvailability())
        {
          auto member = find_if(members.begin(), members.end(),
                                [&book](const Member &m)
                                { return m.getId() == book.getCurrentBorrowerId(); });

          if (member != members.end())
          {
            cout << "Book: " << book.getTitle()
                 << ", Borrowed by: " << member->getName() << endl;
          }
        }
      }
    }
  }

  void listAllBooks()
  {
    cout << "\nAll Books in Library:\n";
    if (books.empty())
    {
      cout << "No books in the library.\n";
      return;
    }
    for (const auto &book : books)
    {
      cout << book.toString() << endl;
    }
  }

  void listAllMembers()
  {
    cout << "\nAll Library Members:\n";
    if (members.empty())
    {
      cout << "No registered members.\n";
      return;
    }
    for (const auto &member : members)
    {
      cout << member.toString() << endl;
    }
  }
};

// Utility function to clear input buffer
void clearInputBuffer()
{
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to get valid integer input
int getIntInput()
{
  int value;
  while (!(cin >> value))
  {
    cout << "Invalid input. Please enter a number: ";
    clearInputBuffer();
  }
  clearInputBuffer();
  return value;
}

int main()
{
  LibrarySystem library;
  string input;

  while (true)
  {
    cout << "\nLibrary Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Remove Book\n";
    cout << "3. Register Member\n";
    cout << "4. Remove Member\n";
    cout << "5. Borrow Book\n";
    cout << "6. Return Book\n";
    cout << "7. Search Books\n";
    cout << "8. Show Overdue List\n";
    cout << "9. Generate Report\n";
    cout << "10. List All Books\n";
    cout << "11. List All Members\n";
    cout << "0. Exit\n";
    cout << "\nEnter your choice: ";

    int choice = getIntInput();

    switch (choice)
    {
    case 0:
      cout << "Thank You! for using the Library Management System.\n";
      return 0;

    case 1:
    {
      string title, author, genre;
      int year;

      cout << "Enter book title: ";
      getline(cin, title);

      cout << "Enter author name: ";
      getline(cin, author);

      cout << "Enter genre: ";
      getline(cin, genre);

      cout << "Enter publication year: ";
      year = getIntInput();

      library.addBook(title, author, genre, year);
      break;
    }

    case 2:
    {
      cout << "Enter book ID to remove: ";
      int bookId = getIntInput();
      library.removeBook(bookId);
      break;
    }

    case 3:
    {
      string name, address, contact;

      cout << "Enter member name: ";
      getline(cin, name);

      cout << "Enter address: ";
      getline(cin, address);

      cout << "Enter contact information: ";
      getline(cin, contact);

      library.registerMember(name, address, contact);
      break;
    }

    case 4:
    {
      cout << "Enter member ID to remove: ";
      int memberId = getIntInput();
      library.removeMember(memberId);
      break;
    }

    case 5:
    {
      cout << "Enter member ID: ";
      int memberId = getIntInput();

      cout << "Enter book ID: ";
      int bookId = getIntInput();

      library.borrowBook(memberId, bookId);
      break;
    }

    case 6:
    {
      cout << "Enter member ID: ";
      int memberId = getIntInput();

      cout << "Enter book ID: ";
      int bookId = getIntInput();

      library.returnBook(memberId, bookId);
      break;
    }

    case 7:
    {
      cout << "Enter search term (title/author/genre): ";
      string searchTerm;
      getline(cin, searchTerm);
      library.searchBooks(searchTerm);
      break;
    }

    case 8:
    {
      library.showOverdueList();
      break;
    }

    case 9:
    {
      library.generateReport();
      break;
    }

    case 10:
    {
      library.listAllBooks();
      break;
    }

    case 11:
    {
      library.listAllMembers();
      break;
    }

    default:
      cout << "Invalid choice. Please try again.\n";
    }
  }

  return 0;
}