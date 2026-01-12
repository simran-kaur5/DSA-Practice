#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int multiplymemo(vector<int>&nums,int i ,int j,vector<vector<int>>&dp){
    if(i==j){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT_MAX;

    for(int k=i;k<j;k++){
        int cost1 = multiplymemo(nums,i,k,dp);
        int cost2 = multiplymemo(nums,k+1,j,dp);

        int currCost = cost1+cost2+(nums[i-1]*nums[k]*nums[j]);

        ans = min(currCost,ans);
    }

    return dp[i][j]=ans;
}
int main(){

    vector<int>nums = {1,2,3,4};
    int n =nums.size();

    vector<vector<int>>dp(n,vector<int>(n,-1));

    cout<<"Minimum number of multiplication operation needed are: "<<multiplymemo(nums,1,n-1,dp);
    
    return 0;
}