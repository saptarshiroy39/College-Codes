#include <iostream>
#include <climits>

#define WHITE 0
#define GREY 1
#define BLACK 2
#define MAX 100

using namespace std;

class Graph
{
public:
  int adj[MAX][MAX]; // Adjacency matrix
  int vertex;

  Graph(int v) : vertex(v)
  {
    for (int i = 0; i < vertex; i++)
    {
      for (int j = 0; j < vertex; j++)
      {
        adj[i][j] = 0;
      }
    }
  }

  void addEdge(int u, int v)
  {
    adj[u][v] = 1;
    adj[v][u] = 1; // For undirected graph
  }
};

// Queue implementation
class Queue
{
public:
  int items[MAX];
  int front, rear;

  Queue() : front(-1), rear(-1) {}

  bool isEmpty()
  {
    return front == -1;
  }

  void enqueue(int value)
  {
    if (rear == MAX - 1)
    {
      cout << "Queue overflow" << endl;
      return;
    }
    if (isEmpty())
    {
      front = 0;
    }
    
    items[++rear] = value;
  }

  int dequeue()
  {
    if (isEmpty())
    {
      cout << "Queue underflow" << endl;
      return -1;
    }
    int item = items[front];

    if (front >= rear)
    {
      front = -1;
      rear = -1;
    }
    else
    {
      front++;
    }
    return item;
  }
};

void BFS(Graph &G, int start)
{
  int color[MAX], pi[MAX], d[MAX];
  Queue q;

  for (int i = 0; i < G.vertex; i++)
  {
    color[i] = WHITE;
    pi[i] = -1;
    d[i] = INT_MAX;
  }

  color[start] = GREY;
  d[start] = 0;
  q.enqueue(start);

  while (!q.isEmpty())
  {
    int u = q.dequeue();
    cout << "Visited " << u << endl;

    for (int v = 0; v < G.vertex; v++)
    {
      if (G.adj[u][v] == 1 && color[v] == WHITE)
      {
        color[v] = GREY;
        q.enqueue(v);
        pi[v] = u;
        d[v] = d[u] + 1;
      }
    }
    color[u] = BLACK;
  }
}

int main()
{
  int vertex, edge, u, v, start;

  cout << "Enter the number of vertices: ";
  cin >> vertex;
  Graph G(vertex);

  cout << "Enter the number of edges: ";
  cin >> edge;

  cout << "Enter edges (u v) for each edge:" << endl;
  for (int i = 0; i < edge; i++)
  {
    cout << "Edge " << i + 1 << ": ";
    cin >> u >> v;
    G.addEdge(u, v);
  }

  cout << "Enter the starting vertex for BFS: ";
  cin >> start;

  cout << "BFS traversal starting from vertex " << start << ":" << endl;
  BFS(G, start);

  return 0;
}