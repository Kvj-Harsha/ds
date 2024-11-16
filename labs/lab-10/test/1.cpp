#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> visited(n + 1, false);  // Using vector for visited array
    vector<vector<int>> adj(n + 1);      // Using vector for adjacency list

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);            // Assuming 1 as the starting node
    visited[1] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << endl;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return 0;
}
