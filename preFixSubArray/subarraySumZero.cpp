#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int zeroSumSubarrays(vector<int>& nums) {
    unordered_map<int,int> m;
    m[0] = 1;

    int sum = 0, count = 0;

    for (int x : nums) {
        sum += x;

        if (m.find(sum) != m.end()) {
            count += m[sum];
        }

        m[sum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {3, -1, -2, 4, -4};
    cout << zeroSumSubarrays(nums);
    return 0;
}
