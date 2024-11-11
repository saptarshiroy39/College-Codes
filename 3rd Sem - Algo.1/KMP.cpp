#include <iostream>
#include <string>
using namespace std;

void prefix_compute(const string &pattern, int *lps, int m)
{
  int i = 1, len = 0;
  while (i < m)
  {
    if (pattern[len] == pattern[i])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else if (len != 0)
    {
      len = lps[len - 1];
    }
    else
    {
      lps[i] = 0;
      i++;
    }
  }
}

void compute_kmp(const string &text, const string &pattern)
{
  int n = text.length(), m = pattern.length();
  int *lps = new int[m]; // Dynamic allocation for LPS array
  lps[0] = 0;            // First element of LPS is always 0

  // Compute the LPS array for the pattern
  prefix_compute(pattern, lps, m);

  int i = 0, j = 0; // i is the index for text, j is the index for pattern

  // Perform the KMP search
  while (i < n)
  {
    if (text[i] == pattern[j])
    {
      i++;
      j++;
    }
    else if (j != 0)
    {
      j = lps[j - 1]; // Use LPS to skip comparisons
    }
    else
    {
      i++; // Move to the next character in the text
    }

    // If j reaches the length of the pattern, a match is found
    if (j == m)
    {
      cout << "Pattern found at index " << i - j << endl; // Output the starting index of the match
      j = lps[j - 1];                                     // Use LPS to continue searching for further matches
    }
  }

  delete[] lps; // Free the dynamically allocated memory
}

int main()
{
  string text, pattern;

  cout << "Enter the text: ";
  getline(cin, text);

  cout << "Enter the pattern: ";
  getline(cin, pattern);

  compute_kmp(text, pattern);

  return 0;
}