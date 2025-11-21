#include <iostream>
#include <vector>
#include <list>
using namespace std;

//
// =====================================================
//            APPROACH 1: GRAPH-BASED (O(n))
// =====================================================
//

class Graph {
public:
    int V;
    list<int>* l;

    Graph(int v) {
        V = v;
        l = new list<int>[V + 1];   // 1-based indexing
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    int centerNode() {
        int center = 1;
        int maxLength = -1;

        for (int i = 1; i <= V; i++) {
            if ((int)l[i].size() > maxLength) {
                maxLength = l[i].size();
                center = i;
            }
        }
        return center;
    }
};

//
// =====================================================
//            APPROACH 2: OPTIMAL (O(1))
// =====================================================
//

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        // ***********************************
        // ** MORE OPTIMAL SOLUTION (O(1)) **
        // ***********************************
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        }
        return edges[0][1];



        // ***********************************
        // ** LESS OPTIMAL GRAPH SOLUTION (O(n)) **
        // ***********************************
        /*
        Graph g(edges.size() + 1);

        for (int i = 0; i < edges.size(); i++) {
            g.addEdge(edges[i][0], edges[i][1]);
        }

        return g.centerNode();
        */
    }
};

int main() {
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {4, 2}
    };

    Solution s;

    cout << "Center of Star Graph = " << s.findCenter(edges) << endl;

    return 0;
}
