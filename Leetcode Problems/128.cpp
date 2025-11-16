#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLength = 0;
        for(int num : s){
            if(s.find(num - 1) == s.end()){
                int currentNum = num, length = 1;
                while(s.find(currentNum + 1) != s.end()){
                    currentNum++;
                    length++;
                }
                maxLength = max(maxLength, length);
            }
        }
        return maxLength;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(nums) << endl; // Output: 4
    return 0;
}
