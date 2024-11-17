#include <iostream>
#include <vector>
using namespace std;

// Recursive function for DFS traversal
void DFSRec(const vector<vector<int>>& adj, vector<bool>& visited, int vertex) 
{
    visited[vertex] = true;

    // Print the current vertex
    cout << vertex << " ";

    // Recursively visit all adjacent vertices
    for (int neighbor : adj[vertex]) {
        if (!visited[neighbor]) {
            DFSRec(adj, visited, neighbor);
        }
    }
}

// Main DFS function that initializes the visited array and calls DFSRec
void DFS(const vector<vector<int>>& adj, int startVertex) 
{
    vector<bool> visited(adj.size(), false); // Visited array
    DFSRec(adj, visited, startVertex);
}

// Function to add an edge to an undirected graph
void addEdge(vector<vector<int>>& adj, int u, int v) 
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V); // Adjacency list representation of the graph

    // Edges to be added
    vector<pair<int, int>> edges = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};
    for (const auto& edge : edges) {
        addEdge(adj, edge.first, edge.second);
    }

    int startVertex = 1; // Starting vertex for DFS
    cout << "DFS traversal starting from vertex " << startVertex << ":\n";
    DFS(adj, startVertex);

    return 0;
}
