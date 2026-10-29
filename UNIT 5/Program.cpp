#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<int> adj[], bool visited[])
{
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < adj[node].size(); i++)
    {
        int neighbour = adj[node][i];

        if (!visited[neighbour])
        {
            DFS(neighbour, adj, visited);
        }
    }
}

int main()
{
    int vertices = 6;

    vector<int> adj[6];

    // Connections between computers
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);

    adj[2].push_back(0);
    adj[2].push_back(4);

    adj[3].push_back(1);

    adj[4].push_back(1);
    adj[4].push_back(2);

    // Computer 5 is disconnected

    bool visited[6] = {false};

    int start;

    cout << "Computer Network DFS Traversal" << endl;
    cout << "Computers are numbered from 0 to 5." << endl;
    cout << "Enter starting computer: ";
    cin >> start;

    if (start < 0 || start >= vertices)
    {
        cout << "Invalid computer number." << endl;
        return 0;
    }

    cout << "Reachable computers: ";

    DFS(start, adj, visited);

    cout << endl;

    return 0;
}
