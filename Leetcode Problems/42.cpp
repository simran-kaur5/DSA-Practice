#include <iostream>
#include <vector>
#include <algorithm>  // for std::max
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int ans = 0;
        int leftMax = 0, rightMax = 0;

        while (l < r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if (leftMax < rightMax) {
                ans += leftMax - height[l];
                l++;
            } else {
                ans += rightMax - height[r];
                r--;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "Trapped water: " << sol.trap(height) << " units" << endl;

    return 0;
}
