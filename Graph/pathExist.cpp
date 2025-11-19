#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* l;

public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool pathExist(int src, int des, vector<bool>& vis) {
        if (src == des) return true;

        vis[src] = true;

        for (int child : l[src]) {
            if (!vis[child]) {
                if (pathExist(child, des, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {

    int n = 7; // number of nodes
    Graph g(n);

    // sample edges
    vector<vector<int>> edges = {
        {0,1}, {0,2}, {1,3}, {2,4},
        {3,4}, {4,5}, {3,5}, {5,6}
    };

    // add edges to graph
    for (auto &e : edges) {
        g.addEdge(e[0], e[1]);
    }

    int src = 0;
    int des = 6;

    vector<bool> vis(n, false);

    bool ans = g.pathExist(src, des, vis);

    if (ans) 
        cout << "Path exists from " << src << " to " << des << endl;
    else 
        cout << "No path exists from " << src << " to " << des << endl;

    return 0;
}
