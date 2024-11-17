#include <iostream>
#include <vector>
using namespace std;

// Function to add an edge to an undirected graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Recursive DFS utility function to explore a graph
void DFSUtil(int u, const vector<int> adj[], vector<bool>& visited)
{
    visited[u] = true;
    // Explore all adjacent vertices
    for (int neighbor : adj[u]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, adj, visited);
        }
    }
}

// Function to count the number of trees in a forest
int countTrees(const vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    int treeCount = 0;

    // Perform DFS for each unvisited vertex
    for (int u = 0; u < V; ++u) {
        if (!visited[u]) {
            DFSUtil(u, adj, visited);  // Explore the tree
            ++treeCount;  // Increment tree count when a new tree is found
        }
    }
    return treeCount;
}

int main()
{
    int V = 5;  // Number of vertices
    vector<int> adj[V];  // Adjacency list representation of the graph

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 3, 4);

    // Output the number of trees (connected components) in the graph
    cout << "Number of trees in the forest: " << countTrees(adj, V) << endl;

    return 0;
}
