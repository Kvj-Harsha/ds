// K V Jaya Harsha
// CS23B1034
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<bool> visited(n, false);
    vector<vector<int>> adj(n);

    char x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        int a = x - 'A';
        int b = y - 'A';
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    stack<int> s;
    s.push(0);
    visited[0] = true;

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        cout << char(node + 'A') << endl; 

        for (int i = 0; i < adj[node].size(); i++)
        {
            int neighbour = adj[node][i];
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                s.push(neighbour); 
            }
        }
    }

    return 0;
}
