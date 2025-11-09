#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = 1; i < nums.size(); i++) {
            // check for numbers missing between consecutive elements
            for (int val = nums[i - 1] + 1; val < nums[i]; val++) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example test cases
    vector<int> nums1 = {3, 7, 5};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> nums3 = {10, 13, 11};

    auto printVector = [](const vector<int>& v) {
        if (v.empty()) cout << "[]";
        else {
            cout << "[";
            for (int i = 0; i < v.size(); i++) {
                cout << v[i];
                if (i != v.size() - 1) cout << ", ";
            }
            cout << "]";
        }
        cout << endl;
    };

    cout << "Missing elements in [3,7,5]: ";
    printVector(sol.findMissingElements(nums1)); // Expected [4, 6]

    cout << "Missing elements in [1,2,3,4]: ";
    printVector(sol.findMissingElements(nums2)); // Expected []

    cout << "Missing elements in [10,13,11]: ";
    printVector(sol.findMissingElements(nums3)); // Expected [12]

    return 0;
}
