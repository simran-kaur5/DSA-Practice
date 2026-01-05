#include<iostream>
#include<vector>
using namespace std;
bool Subset(vector<int>&nums,int target,int n,vector<vector<int>>dp){

    for(int i =1;i<n+1;i++){
        int item = nums[i-1];
        for(int j=1;j<target+1;j++){
            if(item<=j){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-item]+item);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][target]==target;
}
int main(){
    vector<int>nums = {4,2,7,1,3};
    int target=7;
    int n = nums.size();

    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    if(Subset(nums,target,n,dp)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}