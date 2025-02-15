#include <iostream>
using namespace std;

#define M 100 // Define the maximum number of nodes

// Enum to represent color of nodes
enum Color
{
  WHITE,
  GREY,
  BLACK
};
int timeCounter = 0;

// Stack class for topological sorting
class Stack
{
public:
  int data[M];
  int top;

  Stack() : top(-1) {}

  bool isEmpty()
  {
    return top == -1;
  }

  void push(int val)
  {
    if (top < M - 1)
    {
      data[++top] = val;
    }
  }

  int pop()
  {
    if (!isEmpty())
    {
      return data[top--];
    }
    return -1;
  }
};

// Graph class to hold adjacency matrix and perform DFS
class Graph
{
private:
  int adj[M][M]; // Adjacency matrix
  Color color[M];
  int parent[M], discovery[M], finish[M];
  int n;           // Number of vertices
  Stack topoStack; // Stack for topological sorting

public:
  Graph(int vertices) : n(vertices)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        adj[i][j] = 0;
      }
      color[i] = WHITE;
      parent[i] = -1;
      discovery[i] = 0;
      finish[i] = 0;
    }
  }

  void addEdge(int u, int v)
  {
    adj[u][v] = 1;
  }

  void dfsVisit(int u)
  {
    color[u] = GREY;
    cout << " " << u;
    discovery[u] = ++timeCounter;

    for (int v = 0; v < n; v++)
    {
      if (adj[u][v] == 1 && color[v] == WHITE)
      { // Check adjacency
        parent[v] = u;
        dfsVisit(v);
      }
    }

    color[u] = BLACK;
    finish[u] = ++timeCounter;
    topoStack.push(u); // Push node onto stack after finishing
  }

  void dfs(int start)
  {
    for (int u = 0; u < n; u++)
    {
      color[u] = WHITE;
      parent[u] = -1;
    }

    if (color[start] == WHITE)
    {
      dfsVisit(start);
    }

    for (int u = 0; u < n; u++)
    {
      if (color[u] == WHITE)
      {
        dfsVisit(u);
      }
    }

    cout << "\nTopological Sort Order: ";
    while (!topoStack.isEmpty())
    {
      cout << topoStack.pop() << " ";
    }
    cout << "\n";
  }
};

int main()
{
  int n, e, start;
  cout << "Enter the number of vertices: ";
  cin >> n;

  Graph graph(n);

  cout << "Enter the number of edges: ";
  cin >> e;

  cout << "Enter the edges (directed graph):\n";
  for (int i = 0; i < e; i++)
  {
    int u, v;
    cin >> u >> v;
    graph.addEdge(u, v);
  }

  cout << "Enter the starting vertex for DFS: ";
  cin >> start;

  graph.dfs(start);

  return 0;
}