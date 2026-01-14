#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        // dp1: first house allowed, last house NOT allowed
        vector<int> dp1(n - 1, 0);
        // dp2: first house NOT allowed, last house allowed
        vector<int> dp2(n, 0);

        // Base cases
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);

        dp2[0] = 0;        // first house forbidden
        dp2[1] = nums[1];

        // Fill dp1 (houses 0 to n-2)
        for (int i = 2; i < n - 1; i++) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }

        // Fill dp2 (houses 1 to n-1)
        for (int i = 2; i < n; i++) {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }

        return max(dp1[n - 2], dp2[n - 1]);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 2};
    cout << "Maximum money robbed: " << sol.rob(nums) << endl;

    return 0;
}
