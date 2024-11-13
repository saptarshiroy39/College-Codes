#include <iostream>
using namespace std;
#define MAX 100 // Maximum number of edges

struct Edge
{
  int u, v, weight;
};

struct Graph
{
  int V, E;
  Edge edges[MAX];
};

// Union-Find structures
int p[MAX];
int rankArray[MAX]; // Renamed from rank to avoid conflict

// Function to make set
void make_set(int x)
{
  p[x] = x;
  rankArray[x] = 0;
}

// Find-set with path compression
int find_set(int x)
{
  if (x != p[x])
  {
    p[x] = find_set(p[x]);
  }
  return p[x];
}

// Union of two sets using rank
void link(int x, int y)
{
  if (rankArray[x] > rankArray[y])
  {
    p[y] = x;
  }
  else
  {
    p[x] = y;
    if (rankArray[x] == rankArray[y])
    {
      rankArray[y]++;
    }
  }
}

void union_sets(int u, int v)
{
  link(find_set(u), find_set(v));
}

// Selection sort to sort edges by weight
void selectionSortEdges(Edge edges[], int E)
{
  for (int i = 0; i < E - 1; i++)
  {
    int min_idx = i;
    for (int j = i + 1; j < E; j++)
    {
      if (edges[j].weight < edges[min_idx].weight)
      {
        min_idx = j;
      }
    }
    // Swap edges[i] and edges[min_idx]
    Edge temp = edges[i];
    edges[i] = edges[min_idx];
    edges[min_idx] = temp;
  }
}

// Kruskal's algorithm
void kruskalMST(Graph *graph)
{
  int V = graph->V;
  Edge result[MAX]; // Store the result MST
  int e = 0;        // Index for result[]

  // Step 1: Sort all edges in non-decreasing order of weight
  selectionSortEdges(graph->edges, graph->E);

  // Step 2: Initialize disjoint sets for each vertex
  for (int v = 0; v < V; v++)
  {
    make_set(v);
  }

  // Step 3: Iterate through sorted edges
  for (int i = 0; i < graph->E && e < V - 1; i++)
  {
    int u = graph->edges[i].u;
    int v = graph->edges[i].v;

    // Check if the current edge forms a cycle
    if (find_set(u) != find_set(v))
    {
      result[e++] = graph->edges[i]; // Add edge to result
      union_sets(u, v);              // Union the sets
    }
  }

  // Print the result
  cout << "Edges in the Minimum Spanning Tree:\n";
  for (int i = 0; i < e; i++)
  {
    cout << "(" << result[i].u << ", " << result[i].v << ") - Weight: " << result[i].weight << "\n";
  }
}

int main()
{
  int V, E;

  cout << "Enter the number of vertices: ";
  cin >> V;

  cout << "Enter the number of edges: ";
  cin >> E;

  if (E > MAX)
  {
    cout << "Maximum number of edges is " << MAX << ".\n";
    return 1;
  }

  Graph graph;
  graph.V = V;
  graph.E = E;

  cout << "Enter each edge in the format (u v weight):\n";
  for (int i = 0; i < E; i++)
  {
    cout << "Edge " << i + 1 << ": ";
    cin >> graph.edges[i].u >> graph.edges[i].v >> graph.edges[i].weight;
  }

  // Find MST using Kruskal's algorithm
  kruskalMST(&graph);

  return 0;
}