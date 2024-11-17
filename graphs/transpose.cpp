// C++ program to find the transpose of a graph.
#include <iostream>
#include <vector>
using namespace std;

// Function to add an edge from vertex source to vertex destination
void addEdge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
}

// Function to print the adjacency list of a graph
void displayGraph(const vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << " --> ";
        for (int j : adj[i])
            cout << j << " ";
        cout << "\n";
    }
}

// Function to get the transpose of a graph
// Takes the adjacency list of the given graph and fills the adjacency list of the transpose graph
void transposeGraph(const vector<int> adj[], vector<int> transpose[], int v)
{
    // Traverse the adjacency list of the given graph
    // For each edge (u, v), add an edge (v, u) to the transpose graph
    for (int i = 0; i < v; i++)
    {
        for (int j : adj[i])
        {
            addEdge(transpose, j, i);
        }
    }
}

int main()
{
    int v = 5; // Number of vertices
    vector<int> adj[v];

    // Adding edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);

    // Creating the transpose graph
    vector<int> transpose[v];
    transposeGraph(adj, transpose, v);

    // Displaying the adjacency list of the transpose graph
    cout << "Adjacency List of Transpose Graph:\n";
    displayGraph(transpose, v);

    return 0;
}

