#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int LIS(vector<int>&num1,vector<int>&num2,vector<vector<int>>dp){

    int n = num1.size();
    int m = num2.size();

    for(int i =1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(num1[i-1]==num2[j-1]){
                dp[i][j]= 1+ dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }


    return dp[n][m];
}
int main(){

    vector<int>nums1 = {50,3,10,70,40,80};

    unordered_set<int>s(nums1.begin(),nums1.end());

    vector<int>nums2(s.begin(),s.end());

    sort(nums2.begin(),nums2.end());

    int n = nums1.size();
    int m = nums2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    cout<<"Longest increasing sequence of given array is: "<<LIS(nums1,nums2,dp);

    

    return 0;
}