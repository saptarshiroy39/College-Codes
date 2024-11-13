#include <iostream>
#include <climits>
using namespace std;

#define MAX_VERTICES 100

// Function to find the vertex with the minimum key value, from the set of vertices not yet included in MST
int extract_min(int key[], bool mst_flag[], int vertices)
{
  int min = INT_MAX, min_index;

  for (int v = 0; v < vertices; v++)
  {
    if (!mst_flag[v] && key[v] < min)
    {
      min = key[v];
      min_index = v;
    }
  }
  return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], int n, int graph[MAX_VERTICES][MAX_VERTICES])
{
  cout << "Edge   Weight" << endl;
  for (int i = 1; i < n; i++)
  {
    cout << parent[i] << " - " << i << "    " << graph[i][parent[i]] << endl;
  }
}

// Prim's algorithm function to construct and print MST for a graph represented using adjacency matrix
void MST_PRIM(int graph[MAX_VERTICES][MAX_VERTICES], int vertices)
{
  int parent[MAX_VERTICES];    // Array to store constructed MST
  int key[MAX_VERTICES];       // Key values used to pick minimum weight edge in cut
  bool mst_flag[MAX_VERTICES]; // To represent set of vertices not yet included in MST

  // Initialize all keys as infinite and mst_flag[] as false
  for (int i = 0; i < vertices; i++)
  {
    key[i] = INT_MAX;
    mst_flag[i] = false;
  }

  // Always include first vertex in MST.
  key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
  parent[0] = -1; // First node is always root of MST

  // The MST will have vertices-1 edges
  for (int count = 0; count < vertices - 1; count++)
  {
    // Pick the minimum key vertex from the set of vertices not yet included in MST
    int u = extract_min(key, mst_flag, vertices);

    // Add the picked vertex to the MST Set
    mst_flag[u] = true;

    // Update key value and parent index of the adjacent vertices of the picked vertex
    for (int v = 0; v < vertices; v++)
    {
      // graph[u][v] is non-zero only for adjacent vertices of u
      // mst_flag[v] is false for vertices not yet included in MST
      // Update the key only if graph[u][v] is smaller than key[v]
      if (graph[u][v] && !mst_flag[v] && graph[u][v] < key[v])
      {
        parent[v] = u;
        key[v] = graph[u][v];
      }
    }
  }

  // Print the constructed MST
  printMST(parent, vertices, graph);
}

int main()
{
  int vertices, edges;
  int graph[MAX_VERTICES][MAX_VERTICES] = {0};

  cout << "Enter the number of vertices: ";
  cin >> vertices;

  cout << "Enter the number of edges: ";
  cin >> edges;

  cout << "Enter edges with weights (format: src dest weight):" << endl;
  for (int i = 0; i < edges; i++)
  {
    int src, dest, weight;
    cin >> src >> dest >> weight;
    graph[src][dest] = weight;
    graph[dest][src] = weight;
  }

  cout << "Minimum Spanning Tree:" << endl;
  MST_PRIM(graph, vertices);

  return 0;
}