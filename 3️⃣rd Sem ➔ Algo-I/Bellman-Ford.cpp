#include <iostream>
#include <climits>
using namespace std;

#define INF INT_MAX 
#define NIL -1

struct Edge
{
  int u, v, w;
};

// Function to initialize single source
void initialize_single_source(int V, int s, int d[], int pi[])
{
  for (int i = 0; i < V; i++)
  {
    d[i] = INF;  // Set distance to all vertices as infinity
    pi[i] = NIL; // Set predecessor to NIL for all vertices
  }
  d[s] = 0; // Distance to source vertex is 0
}

// Relax function to update distances
void relax(int u, int v, int w, int d[], int pi[])
{
  if (d[v] > (d[u] + w))
  {
    d[v] = d[u] + w;
    pi[v] = u;
  }
}

// Bellman-Ford algorithm to find shortest paths
bool BellmanFord(int V, int E, Edge edges[], int s, int d[], int pi[])
{
  initialize_single_source(V, s, d, pi);

  // Relax all edges |V| - 1 times
  for (int i = 1; i <= V - 1; i++)
  {
    for (int j = 0; j < E; j++)
    {
      relax(edges[j].u, edges[j].v, edges[j].w, d, pi);
    }
  }

  // Check for negative weight cycles
  for (int j = 0; j < E; j++)
  {
    if (d[edges[j].v] > (d[edges[j].u] + edges[j].w))
    {
      return false; // Negative weight cycle detected
    }
  }

  return true; // No negative weight cycle
}

// Function to print the shortest path distances and predecessors
void print_result(int V, int d[], int pi[])
{
  cout << "Vertex\tDistance from Source\tPredecessor\n";
  for (int i = 0; i < V; i++)
  {
    cout << i << "\t";
    if (d[i] == INF)
    {
      cout << "INF\t";
    }
    else
    {
      cout << d[i] << "\t";
    }
    cout << pi[i] << endl;
  }
}

int main()
{
  int V, E;

  cout << "Enter the number of vertices: ";
  cin >> V;

  cout << "Enter the number of edges: ";
  cin >> E;

  Edge edges[E];

  cout << "Enter the edges (source, destination, weight):\n";
  for (int i = 0; i < E; i++)
  {
    cout << "Edge " << i + 1 << ": ";
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  }

  int source;
  cout << "Enter the source vertex: ";
  cin >> source;

  int d[V];  // Distance array
  int pi[V]; // Predecessor array

  bool result = BellmanFord(V, E, edges, source, d, pi);

  if (result)
  {
    cout << "Shortest path distances from source " << source << ":\n";
    print_result(V, d, pi);
  }
  else
  {
    cout << "Graph contains a negative weight cycle.\n";
  }

  return 0;
}