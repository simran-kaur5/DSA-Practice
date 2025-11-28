#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> vis(V, false);
        int minCost = 0;

        pq.push({0, 0}); // {cost, node}

        while(!pq.empty()) {
            pair<int,int>curr= pq.top();
            int cost = curr.first;
            int u = curr.second;
            pq.pop();

            if(vis[u]) continue;

            vis[u] = true;
            minCost += cost;

            for(int v = 0; v < V; v++) {
                if(!vis[v]) {
                    int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    pq.push({wt, v});
                }
            }
        }

        return minCost;
    }
};

int main() {
    // Example input
    vector<vector<int>> points = {
        {0,0}, {2,2}, {3,10}, {5,2}, {7,0}
    };

    Solution s;
    int result = s.minCostConnectPoints(points);

    cout << "Minimum Cost to Connect All Points: " << result << endl;

    return 0;
}
