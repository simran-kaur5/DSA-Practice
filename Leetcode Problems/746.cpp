#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) {
        int n = nums.size();

        // dp[i] = min cost to reach step i (paying cost of step i)
        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = nums[1];

        for (int i = 2; i < n; i++) {
            dp[i] = nums[i] + min(dp[i - 1], dp[i - 2]);
        }

        // TOP has no cost
        return min(dp[n - 1], dp[n - 2]);
    }
};

int main() {
    Solution s;
    vector<int> nums = {10, 15, 20};

    cout << "Minimum cost to reach the top: "
         << s.minCostClimbingStairs(nums) << endl;

    return 0;
}
