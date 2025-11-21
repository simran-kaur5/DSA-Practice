#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> indegree(n+1, 0);   // how many trust i
        vector<int> outdegree(n+1, 0);  // how many i trusts

        for (auto &t : trust) {
            int a = t[0];
            int b = t[1];

            outdegree[a]++;   // a trusts someone
            indegree[b]++;    // b is trusted by someone
        }

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;   // judge found
            }
        }

        return -1;  // no judge
    }
};

int main() {

    Solution sol;

    int n = 3;
    vector<vector<int>> trust = {
        {1, 3},
        {2, 3}
    };

    int judge = sol.findJudge(n, trust);

    if (judge == -1) {
        cout << "No judge exists." << endl;
    } else {
        cout << "The town judge is: " << judge << endl;
    }

    return 0;
}
