#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int EvenSumSubArray(vector<int>& nums, int n) {
    unordered_map<int,int> m;
    m[0] = 1;

    int count = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];

        int rem = sum % 2;
        if (rem < 0) rem += 2;   // fix negative remainder

        if (m.find(rem) != m.end()) {
            count += m[rem];
        }
        m[rem]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();

    cout << EvenSumSubArray(nums, n);
    return 0;
}
