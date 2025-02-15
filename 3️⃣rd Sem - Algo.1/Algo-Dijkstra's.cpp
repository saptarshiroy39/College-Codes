#include <iostream>
#include <climits>
using namespace std;

#define INF INT_MAX
#define Max 100

// Initialize single source function
void initialize_single_source(int dist[], int pred[], int src, int V)
{
  for (int i = 0; i < V; i++)
  {
    dist[i] = INF;
    pred[i] = -1;
  }
  dist[src] = 0;
}

// Relax function to update the distance of adjacent vertices
void relax(int u, int v, int weight, int dist[], int pred[])
{
  if (dist[u] != INF && dist[v] > dist[u] + weight)
  {
    dist[v] = dist[u] + weight;
    pred[v] = u;
  }
}

// Find vertex with minimum distance from the source that is not yet processed
int extract_min(int dist[], bool visited[], int V)
{
  int min = INF, min_index = -1;
  for (int v = 0; v < V; v++)
  {
    if (!visited[v] && dist[v] <= min)
    {
      min = dist[v];
      min_index = v;
    }
  }
  return min_index;
}

// Dijkstra's algorithm
void dijkstra(int graph[Max][Max], int V, int src)
{
  int dist[Max];
  int pred[Max];           // To store the shortest path tree
  bool visited[Max] = {0}; // to mark visited vertices

  initialize_single_source(dist, pred, src, V);

  for (int i = 0; i < V - 1; i++)
  {
    int u = extract_min(dist, visited, V);

    if (u == -1)
    {
      break; // All reachable nodes are processed
    }
    visited[u] = true;

    for (int v = 0; v < V; v++)
    {
      if (graph[u][v] && !visited[v])
      { // If v is adjacent and not yet visited
        relax(u, v, graph[u][v], dist, pred);
      }
    }
  }

  // Print the shortest distances from source
  cout << "Vertex\tDistance from Source\tPredecessor\n";
  for (int i = 0; i < V; i++)
  {
    cout << i << "\t\t" << dist[i] << "\t\t\t" << pred[i] << endl;
  }
}

// Driver program to test the above functions
int main()
{
  int V, E;
  cout << "Enter the number of vertices: ";
  cin >> V;

  int graph[Max][Max] = {0}; // Initialize a 2D array to represent the graph

  cout << "Enter the number of edges: ";
  cin >> E;

  cout << "Enter the edges in the format (u, v, weight):\n";
  for (int i = 0; i < E; i++)
  {
    int u, v, weight;
    cin >> u >> v >> weight;
    graph[u][v] = weight;
    graph[v][u] = weight; // For an undirected graph
  }

  int source;
  cout << "Enter the source vertex: ";
  cin >> source;

  dijkstra(graph, V, source); // Running Dijkstra's algorithm

  return 0;
}