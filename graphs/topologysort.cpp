#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to perform DFS and topological sorting
void topologicalSortUtil(int v, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& Stack)
{
    visited[v] = true;

    // Recur for all adjacent vertices
    for (size_t i = 0; i < adj[v].size(); ++i) {
        int neighbor = adj[v][i];
        if (!visited[neighbor]) {
            topologicalSortUtil(neighbor, adj, visited, Stack);
        }
    }

    // Push the current vertex to the stack which stores the result
    Stack.push(v);
}

// Function to perform Topological Sort
void topologicalSort(const vector<vector<int>>& adj, int V)
{
    stack<int> Stack; // Stack to store the result
    vector<bool> visited(V, false);

    // Call the recursive helper function to store
    // Topological Sort starting from all vertices one by one
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, Stack);
        }
    }

    // Print contents of stack (the topological sort)
    cout << "Topological sorting of the graph: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}

int main()
{
    // Number of vertices
    int V = 4;

    // List of edges
    vector<pair<int, int>> edges = { {0, 1}, {1, 2}, {3, 1}, {3, 2} };

    // Graph represented as an adjacency list
    vector<vector<int>> adj(V);

    // Building the graph from the edges
    for (const auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
    }

    // Perform topological sort and print the result
    topologicalSort(adj, V);

    return 0;
}
