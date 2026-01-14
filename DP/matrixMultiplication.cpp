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

int multiplyTab(vector<int>&nums){
    int n = nums.size();
    vector<vector<int>>dp(n,vector<int>(n,0));

    for(int i=1;i<n;i++){//all diagonals must be 0 because i==j
        dp[i][i]=0;
    }


    for(int len =2;len<n;len++){
        for(int i=1;i<=n-len;i++){
            int j = i+len-1;
            dp[i][j]=INT_MAX;

            //where to partition
            for(int k=i;k<j;k++){
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];

                int currCost = cost1 + cost2 + nums[i-1]*nums[k]*nums[j];

                dp[i][j]=min(currCost,dp[i][j]);
            }
        }
    }

    return dp[1][n-1];
}
int main(){

    vector<int>nums = {1,2,3,4};
    int n =nums.size();

    // vector<vector<int>>dp(n,vector<int>(n,-1));

    cout<<"Minimum number of multiplication operation needed are: "<<multiplyTab(nums);
    
    return 0;
}