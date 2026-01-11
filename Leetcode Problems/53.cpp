#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];

        int maxSub = dp[0];

        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            maxSub = max(maxSub, dp[i]);
        }

        // Debug print (optional)
        cout << "DP array: ";
        for (int i = 0; i < n; i++) {
            cout << dp[i] << " ";
        }
        cout << endl;

        return maxSub;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int ans = sol.maxSubArray(nums);
    cout << "Maximum Subarray Sum = " << ans << endl;

    return 0;
}
