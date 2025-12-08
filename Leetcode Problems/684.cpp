#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> par;
    vector<int> rankArr;

    int find(int x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void unionByRank(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;

        if(rankArr[pu] == rankArr[pv]){
            par[pv] = pu;
            rankArr[pu]++;
        } else if(rankArr[pu] > rankArr[pv]) {
            par[pv] = pu;
        } else {
            par[pu] = pv;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        par.resize(n+1);
        rankArr.resize(n+1, 0);

        for(int i = 1; i <= n; i++){
            par[i] = i;     // ✔️ Correct initialization
        }

        vector<int> ans;

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            if(find(u) == find(v)){
                return {u, v};
            }

            unionByRank(u, v);
        }

        return {};
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};

    vector<int> result = s.findRedundantConnection(edges);

    cout << "Redundant Edge: [" << result[0] << "," << result[1] << "]" << endl;
    return 0;
}
