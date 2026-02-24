#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();

        // Sort both arrays
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0; // arrival pointer
        int j = 0; // departure pointer
        int curr = 0; // current platforms in use
        int ans = 0;  // maximum platforms needed

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                curr++;              // one train arrived
                ans = max(ans, curr);
                i++;
            } else {
                curr--;              // one train departed
                j++;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    Solution obj;
    cout << "Minimum Platforms Required = " 
         << obj.minPlatform(arr, dep) << endl;

    return 0;
}