#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPath(int i, int j, int m, int n,
                vector<vector<int>>& matrix,
                vector<vector<int>>& dp) {

        // memoization check
        if (dp[i][j] != 1) {
            return dp[i][j];
        }

        // down
        if (i + 1 < m && matrix[i][j] < matrix[i + 1][j]) {
            dp[i][j] = max(dp[i][j],
                            maxPath(i + 1, j, m, n, matrix, dp) + 1);
        }

        // right
        if (j + 1 < n && matrix[i][j] < matrix[i][j + 1]) {
            dp[i][j] = max(dp[i][j],
                            maxPath(i, j + 1, m, n, matrix, dp) + 1);
        }

        // left
        if (j - 1 >= 0 && matrix[i][j] < matrix[i][j - 1]) {
            dp[i][j] = max(dp[i][j],
                            maxPath(i, j - 1, m, n, matrix, dp) + 1);
        }

        // up
        if (i - 1 >= 0 && matrix[i][j] < matrix[i - 1][j]) {
            dp[i][j] = max(dp[i][j],
                            maxPath(i - 1, j, m, n, matrix, dp) + 1);
        }

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 1));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, maxPath(i, j, m, n, matrix, dp));
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    Solution sol;
    cout << "Longest Increasing Path Length: "
         << sol.longestIncreasingPath(matrix) << endl;

    return 0;
}
