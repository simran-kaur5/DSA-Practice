#include<iostream>
#include<vector>
using namespace std;
int knapsack(vector<int>&val,vector<int>&w,int W,int n,vector<vector<int>>dp){

    for(int i =1;i<n+1;i++){
        int itemVal = val[i-1];
        int itemW = w[i-1];

        for(int j=1;j<W+1;j++){
            if(itemW<=j){
                //include
                dp[i][j]=max(itemVal+dp[i][j-itemW],dp[i-1][j]);
            }else{//exclude
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main(){
    vector<int>val = {15,14,10,45,30};
    vector<int>w = {2,5,1,3,4};
    int W=7;
    int n=5;

    vector<vector<int>>dp(n+1,vector<int>(W+1,0));

    cout<<"Max value that can be added in knapSack: "<<knapsack(val,w,W,n,dp);
    return 0;
}