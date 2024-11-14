#include <iostream>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2
#define MAX 100

int color[MAX];
int pi[MAX];
int d[MAX];
int f[MAX];
int time;
int adj[MAX][MAX]; // Adjacency matrix for representing the graph
int V;             // Number of vertices
int E;             // Number of edges

void DFS_Visit(int u)
{
  color[u] = GREY;
  d[u] = ++time;

  for (int v = 0; v < V; v++)
  {
    if (adj[u][v] == 1)
    { // If there's an edge from u to v
      if (color[v] == WHITE)
      {
        pi[v] = u;
        DFS_Visit(v);
      }
    }
  }

  color[u] = BLACK;
  f[u] = ++time;
}

void DFS()
{
  for (int i = 0; i < V; i++)
  {
    color[i] = WHITE;
    pi[i] = -1; // NIL is represented by -1
  }
  time = 0;

  for (int u = 0; u < V; u++)
  {
    if (color[u] == WHITE)
    {
      DFS_Visit(u);
    }
  }
}

int main()
{
  cout << "Enter the number of vertices: ";
  cin >> V;

  cout << "Enter the number of edges: ";
  cin >> E;

  // Initialize the adjacency matrix with 0s
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      adj[i][j] = 0;
    }
  }

  // Input the edges
  cout << "Enter each edge (u v) as a pair of space-separated vertices (0-based index):\n";
  for (int i = 0; i < E; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1; // Create a directed edge from u to v
  }

  DFS();

  // Output discovery and finish times
  cout << "Vertex\tDiscovery\tFinish\n";
  for (int i = 0; i < V; i++)
  {
    cout << i << "\t" << d[i] << "\t\t" << f[i] << "\n";
  }

  return 0;
}
