#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<bool> visited(n + 1, false); // Track visited nodes
    vector<vector<int>> adj(n + 1);     // Adjacency list

    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Assuming an undirected graph
    }

    stack<int> s;
    s.push(1); // Start DFS from node 1
    visited[1] = true;

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        cout << node << endl;

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return 0;
}
