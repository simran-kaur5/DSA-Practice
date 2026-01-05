#include<iostream>
#include<vector>
using namespace std;
int knapSack(vector<int>&val,vector<int>&w,int W,int n,vector<vector<int>>&dp){
    if(W==0 || n==0){
        return 0;
    }
    
    if(dp[n][W]!=-1){
        return dp[n][W];
    }

    int itemWt = w[n-1];
    int itemVal = val[n-1];
    if(itemWt<=W){ //possible to include exclude both
        int ans1 = knapSack(val,w,W-itemWt,n-1,dp)+itemVal; //include

        int ans2 = knapSack(val,w,W,n-1,dp); //exclude 

        dp[n][W]=max(ans1,ans2);
        return dp[n][W];
    }else{

        return dp[n][W]=knapSack(val,w,W,n-1,dp);
    }
}
int main(){

    vector<int>val = {15,14,10,45,30};
    vector<int>w = {2,5,1,3,4};
    int n = val.size();
    int W = 7;

    vector<vector<int>>dp(n+1,vector<int>(W+1,-1));

    cout<<knapSack(val,w,W,n,dp);
    return 0;
}