// K V Jaya Harsha
// CS23B1034
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;

    vector<bool> visited(n + 1, false);
    vector<vector<int>> adj(n + 1);

    char x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        int a = x - 'A';
        int b = y - 'A';
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<char> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << char(node + 'A') << endl;

        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return 0;
}

