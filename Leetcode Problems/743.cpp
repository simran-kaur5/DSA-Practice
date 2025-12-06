#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Min-heap (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // adjacency list: graph[u] = vector of {v, weight}
        vector<vector<pair<int,int>>> graph(n+1);

        for(auto &t : times){
            graph[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dis(n+1, INT_MAX);
        dis[k] = 0;

        pq.push({0, k});

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int currDist = curr.first;
            int node = curr.second;

            // Skip stale entries
            if(currDist > dis[node]) continue;

            for(auto &nbr : graph[node]){
                int nextNode = nbr.first;
                int weight = nbr.second;

                if(dis[nextNode] > currDist + weight){
                    dis[nextNode] = currDist + weight;
                    pq.push({dis[nextNode], nextNode});
                }
            }
        }

        int maxTime = 0;
        for(int i = 1; i <= n; i++){
            if(dis[i] == INT_MAX) return -1; // unreachable
            maxTime = max(maxTime, dis[i]);
        }

        return maxTime;
    }
};

int main() {
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;

    Solution sol;
    cout << "Output: " << sol.networkDelayTime(times, n, k) << endl;

    return 0;
}
