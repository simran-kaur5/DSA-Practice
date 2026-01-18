#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySumEqualsK(vector<int>& nums, int k) {
    unordered_map<int,int> m;
    m[0] = 1;

    int sum = 0, count = 0;

    for (int x : nums) {
        sum += x;

        if (m.find(sum - k) != m.end()) {
            count += m[sum - k];
        }

        m[sum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 2, 2, 4};
    int k = 4;

    cout << subarraySumEqualsK(nums, k);
    return 0;
}
