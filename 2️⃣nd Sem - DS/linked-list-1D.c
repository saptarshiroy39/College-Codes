#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
  int data;
  struct ListNode *next;
} Node;

Node *create(int data)
{
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Insert at BEGINNING
void insertBeginning(Node **head, int data)
{
  Node *newNode = create(data);
  newNode->next = *head;
  *head = newNode;
}

// Insert at END
void insertEnd(Node **head, int data)
{
  Node *newNode = create(data);
  if (*head == NULL)
  {
    *head = newNode;
    return;
  }
  Node *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

// Delete a NODE
void deleteNode(Node **head, int key)
{
  Node *temp = *head;
  Node *prev = NULL;
  while (temp != NULL && temp->data != key)
  {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL)
    return;
  if (prev == NULL)
    *head = temp->next;
  else
    prev->next = temp->next;
  free(temp);
}

// DISPLAY Linked-List
void display(Node *head)
{
  while (head != NULL)
  {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

// REVERSE list
void reverse(Node **head)
{
  Node *prev = NULL;
  Node *current = *head;
  Node *next = NULL;
  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

// Main function
int main()
{
  Node *head = NULL;
  int choice, data, key;

  while (1)
  {
    printf("1. INSERT at BEGINNING\n");
    printf("2. INSERT at END\n");
    printf("3. DELETE a NODE\n");
    printf("4. DISPLAY list\n");
    printf("5. REVERSE list\n");
    printf("6. EXIT\n");

    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice)
    {
    case 1:
      printf("Enter data to insert at beginning : ");
      scanf("%d", &data);
      insertBeginning(&head, data);
      break;

    case 2:
      printf("Enter data to insert at end : ");
      scanf("%d", &data);
      insertEnd(&head, data);
      break;

    case 3:
      printf("Enter data to delete : ");
      scanf("%d", &key);
      deleteNode(&head, key);
      break;

    case 4:
      printf("Linked list : ");
      display(head);
      break;

    case 5:
      printf("Reversed linked list : ");
      reverse(&head);
      display(head);
      reverse(&head);
      break;

    case 6:
      printf("Exiting...");
      return 0;

    default:
      printf("Invalid choice!");
    }
  }
  return 0;
}