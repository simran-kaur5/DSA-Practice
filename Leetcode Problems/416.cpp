#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int W = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++) {
            int itemW = nums[i - 1];
            for (int j = 1; j <= W; j++) {
                if (itemW <= j) {
                    dp[i][j] = max(itemW + dp[i - 1][j - itemW],
                                   dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        int group2 = sum - dp[n][W];
        return abs(dp[n][W] - group2) == 0;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 5, 11, 5};  // Test case
    // vector<int> nums = {1, 2, 3, 5}; // Try this also

    if (obj.canPartition(nums)) {
        cout << "True (Can be partitioned into equal sum subsets)" << endl;
    } else {
        cout << "False (Cannot be partitioned)" << endl;
    }

    return 0;
}
