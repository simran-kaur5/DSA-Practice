#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void BFShelper(int i, vector<bool> &vis)
    { // TC -> O(V+E)
        queue<int> q;

        q.push(i);
        vis[i] = true;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int v : l[curr])
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void BFS()
    {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                BFShelper(i, vis);
            }
        }
    }

    void print()
    {
        for (int idx = 0; idx < V; idx++)
        {

            cout << idx << " : [ ";
            for (int v : l[idx])
            {
                cout << "[ " << v << "] ";
            }
            cout << " ] ";
            cout << endl;
        }
    }
};
int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 5);
    g.addEdge(5, 6);

    g.BFS();

    return 0;
}