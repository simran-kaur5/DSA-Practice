#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    
    if (n == 1) return nums[0];

    vector<int> bestRob(n);
    bestRob[0] = nums[0];
    bestRob[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        bestRob[i] = max(
            bestRob[i - 1],           // skip current house
            bestRob[i - 2] + nums[i]  // rob current house
        );
    }

    return bestRob[n - 1];
}

int main() {
    vector<int> nums = {2, 1, 1, 2};

    cout << "Maximum money that can be robbed: "
         << rob(nums) << endl;

    return 0;
}
