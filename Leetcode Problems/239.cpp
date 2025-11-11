#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Function to compute the maximum of each sliding window
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // Edge case: if window size = 1, return nums directly
    if (k == 1) {
        return nums;
    }

    deque<int> dq;          // stores indices of useful elements
    vector<int> ans;        // stores final result (max of each window)

    // Process the first window
    for (int i = 0; i < k; i++) {
        // Remove smaller elements from back
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(nums[dq.front()]);

    // Process the rest of the elements
    for (int i = k; i < nums.size(); i++) {
        // Remove indices that are out of the current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove smaller elements (not useful)
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        // Add current element index
        dq.push_back(i);

        // The front is the largest element in the current window
        ans.push_back(nums[dq.front()]);
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
