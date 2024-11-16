//CS23B1034
//K V Jaya Harsha




#include <iostream>
using namespace std;

int main()
{
    int vertices;
    cin >> vertices;

    int adj[vertices][vertices];
    
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            adj[i][j] = 0;
        }
    }

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
            adj[i][versec] = edgeval;  
        }
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < vertices; i++)a
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nAdjacent nodes for each vertex:" << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << "Vertex " << i << ":";
        bool hasAdjacents = false; 
        for (int j = 0; j < vertices; j++)
        {
            if (adj[i][j] != 0)
            {
                cout << " " << j << "(weight: " << adj[i][j] << ")";
                hasAdjacents = true;
            }
        }
        if (!hasAdjacents)
        {
            cout << " No adjacent nodes";
        }
        cout << endl;
    }

    return 0;
}
