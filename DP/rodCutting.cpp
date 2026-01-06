#include<iostream>
#include<vector>
using namespace std;
int rodCut(vector<int>&price,vector<int>&length,int n,int rodLength,vector<vector<int>>&dp){

    for(int i=1;i<n+1;i++){
        int p=price[i-1];
        int l=length[i-1];

        for(int j=1;j<rodLength+1;j++){
            if(l<=j){
                dp[i][j]=max(dp[i-1][j],p+dp[i][j-l]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][rodLength];
}
int main(){

    vector<int>price={1,5,8,9,10,17,17,10};
    vector<int>length={1,2,3,4,5,6,7,8};

    int n=8;
    int rodLength=8;

    vector<vector<int>>dp(n+1,vector<int>(rodLength+1,0));

    cout<<"Max price that we get from cutting the rod: "<<rodCut(price,length,n,rodLength,dp);
    return 0;
}