// CS23B1034
// K V Jaya Harsha
#include <iostream>
using namespace std;

int main()
{
    int vertices;
    cin >> vertices;
    int edges;
    cin >> edges;
    int adj[vertices][vertices];
    for (int i = 0; i < vertices; i++)
    {
        int tempgroup;
        cin >> tempgroup;
        for (int j = 0; j < tempgroup; j++)
        {
            int versec;
            cin >> versec;
            int edgeval;
            cin >> edgeval;
            adj[vertices][versec] = edgeval;
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; i < vertices; i++)
        {
            cout << adj[vertices][vertices];
        }
    }

    return 0;
}