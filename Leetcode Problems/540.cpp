#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        if (n == 1) {
            return nums[0];
        }

        while (high > low) {
            int mid = low + (high - low) / 2;

            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            } else {
                if (nums[mid] == nums[mid + 1]) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
        }

        return nums[low];
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1,1,2,3,3,4,4,8,8};
    vector<int> nums2 = {3,3,7,7,10,11,11};
    vector<int> nums3 = {1,1,2,2,5};
    vector<int> nums4 = {7};

    cout << obj.singleNonDuplicate(nums1) << endl;  // 2
    cout << obj.singleNonDuplicate(nums2) << endl;  // 10
    cout << obj.singleNonDuplicate(nums3) << endl;  // 5
    cout << obj.singleNonDuplicate(nums4) << endl;  // 7

    return 0;
}