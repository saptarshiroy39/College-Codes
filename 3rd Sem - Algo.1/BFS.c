#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define WHITE 0
#define GREY 1
#define BLACK 2
#define MAX 100

typedef struct
{
  int adj[MAX][MAX]; // Adjacency matrix
  int vertex;
} Graph;

typedef struct
{
  int items[MAX];
  int front, rear;
} Queue;

// Initialize queue
void initQueue(Queue *q)
{
  q->front = -1;
  q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue *q)
{
  return q->front == -1;
}

// Enqueue
void enqueue(Queue *q, int value)
{
  if (q->rear == MAX - 1)
  {
    printf("Queue overflow\n");
    return;
  }
  if (isEmpty(q))
  {
    q->front = 0;
  }

  q->items[++q->rear] = value;
}

// Dequeue
int dequeue(Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue underflow\n");
    return -1;
  }
  int item = q->items[q->front];

  if (q->front >= q->rear)
  {
    q->front = -1;
    q->rear = -1;
  }
  else
  {
    q->front++;
  }

  return item;
}

// BFS function
void BFS(Graph *G, int start)
{
  int color[MAX], pi[MAX], d[MAX];
  Queue q;
  initQueue(&q);

  for (int i = 0; i < G->vertex; i++)
  {
    color[i] = WHITE;
    pi[i] = -1;
    d[i] = INT_MAX;
  }

  color[start] = GREY;
  d[start] = 0;
  enqueue(&q, start);

  while (!isEmpty(&q))
  {
    int u = dequeue(&q);
    printf("Visited %d\n", u);

    for (int v = 0; v < G->vertex; v++)
    {
      if (G->adj[u][v] == 1 && color[v] == WHITE)
      {
        color[v] = GREY;
        enqueue(&q, v);
        pi[v] = u;
        d[v] = d[u] + 1;
      }
    }
    color[u] = BLACK;
  }
}

// Add edge to the graph
void addEdge(Graph *G, int u, int v)
{
  G->adj[u][v] = 1;
  G->adj[v][u] = 1; // For undirected graph
}

int main()
{
  Graph G;
  int edge, u, v, start;

  printf("Enter the number of vertices: ");
  scanf("%d", &G.vertex);

  // Initialize adjacency matrix
  for (int i = 0; i < G.vertex; i++)
  {
    for (int j = 0; j < G.vertex; j++)
    {
      G.adj[i][j] = 0;
    }
  }

  printf("Enter the number of edges: ");
  scanf("%d", &edge);

  printf("Enter edges (u v) for each edge:\n");
  for (int i = 0; i < edge; i++)
  {
    printf("Edge %d: ", i + 1);
    scanf("%d %d", &u, &v);
    addEdge(&G, u, v);
  }

  printf("Enter the starting vertex for BFS: ");
  scanf("%d", &start);

  printf("BFS traversal starting from vertex %d:\n", start);
  BFS(&G, start);

  return 0;
}