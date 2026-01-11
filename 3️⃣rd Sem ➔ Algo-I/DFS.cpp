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

class Graph
{
public:
  int vertex;
  int adj[MAX][MAX];

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
};

void DFS_Visit(Graph &G, int u)
{
  color[u] = GREY;
  d[u] = ++time;

  for (int v = 0; v < G.vertex; v++)
  {
    if (G.adj[u][v] == 1)
    { // If there's an edge from u to v
      if (color[v] == WHITE)
      {
        pi[v] = u;
        DFS_Visit(G, v);
      }
    }
  }

  color[u] = BLACK;
  f[u] = ++time;
}

void DFS(Graph &G)
{
  for (int i = 0; i < G.vertex; i++)
  {
    color[i] = WHITE;
    pi[i] = -1; // NIL is represented by -1
  }

  time = 0;

  for (int u = 0; u < G.vertex; u++)
  {
    if (color[u] == WHITE)
    {
      DFS_Visit(G, u);
    }
  }
}

int main()
{
  int vertex,edge;
  int u,v;

  cout << "Enter the number of vertices: ";
  cin >> vertex;
  Graph G(vertex);

  cout << "Enter the number of edges: ";
  cin >> edge;

  // Input the edges
  cout << "Enter edges (u v) for each edge:" << endl;
  for (int i = 0; i < edge; i++)
  {
    cout << "Edge "<< i+1 << ": ";
    cin >> u >> v;
    
    G.adj[u][v] = 1; // Create a directed edge from u to v
  }

  DFS(G);

  // Output discovery and finish times
  cout << "Vertex\tDiscovery\tFinish\n";
  for (int i = 0; i < vertex; i++)
  {
    cout << i << "\t" << d[i] << "\t\t" << f[i] << "\n";
  }

  return 0;
}