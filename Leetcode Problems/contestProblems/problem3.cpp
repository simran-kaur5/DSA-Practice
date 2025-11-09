#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEl = *max_element(nums.begin(), nums.end());
        int moves = 0;
        for (int x : nums) moves += maxEl - x;
        return moves;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 1, 3};
    cout << sol.minMoves(nums) << endl; // Expected 3
    return 0;
}
