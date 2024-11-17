#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to perform BFS from a given source vertex `s`
void bfs(const vector<vector<int>>& adj, int s, vector<bool>& visited) 
{
    queue<int> q; // Queue for BFS

    // Mark the source vertex as visited and enqueue it
    visited[s] = true;
    q.push(s);

    // Process the queue
    while (!q.empty()) {
        int curr = q.front(); // Get the front element
        q.pop();
        cout << curr << " "; // Print the current vertex

        // Explore all adjacent vertices of `curr`
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark as visited
                q.push(neighbor); // Enqueue it
            }
        }
    }
}

// Function to perform BFS for the entire graph (handles disconnected graphs)
void bfsDisconnected(const vector<vector<int>>& adj) 
{
    vector<bool> visited(adj.size(), false); // Visited array

    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i]) {
            bfs(adj, i, visited); // Start BFS from unvisited vertex
        }
    }
}

// Function to add an undirected edge to the graph
void addEdge(vector<vector<int>>& adj, int u, int v) 
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{
    int V = 6; // Number of vertices

    // Adjacency list representation of the graph
    vector<vector<int>> adj(V);

    // Adding edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);

    cout << "BFS traversal of the graph:\n";
    bfsDisconnected(adj);

    return 0;
}
