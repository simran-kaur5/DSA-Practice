#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        long long orgSum = 0;

        for(int i=0;i<n;i++){
            orgSum += abs(nums1[i]-nums2[i]);
        }

        vector<int>sorted = nums1;
        sort(sorted.begin(),sorted.end());

        long long maintainOrg = orgSum;

        for(int i=0;i<n;i++){
            auto it = lower_bound(sorted.begin(),sorted.end(),nums2[i]);

            long long sum = maintainOrg - abs(nums1[i]-nums2[i]);

            int prevSum = INT_MAX;
            int nextSum = INT_MAX;
            int minBoth = abs(nums1[i]-nums2[i]);

            if(it!=sorted.end() && it!=sorted.begin()){
                int prev = *(it-1);
                nextSum = abs(nums2[i]-(*it));
                prevSum = abs(nums2[i]-prev);
                minBoth = min(nextSum,prevSum);
            }
            else if(it!=sorted.begin()){
                int prev = *(it-1);
                prevSum = abs(nums2[i]-prev);
                minBoth = min(minBoth,prevSum);
            }
            else if(it!=sorted.end()){
                nextSum = abs(nums2[i]-(*it));
                minBoth = min(minBoth,nextSum);
            }

            sum += minBoth;
            orgSum = min(orgSum,sum);
        }

        return orgSum % 1000000007;
    }
};

int main() {

    vector<int> nums1 = {1, 7, 5};
    vector<int> nums2 = {2, 3, 5};

    Solution obj;

    cout << obj.minAbsoluteSumDiff(nums1, nums2) << endl;

    return 0;
}