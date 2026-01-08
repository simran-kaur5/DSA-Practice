#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int LCS_subStr(string str1,string str2,vector<vector<int>>&dp){

    int n=str1.length();
    int m = str2.length();
    int ans = 0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans= max(ans,dp[i][j]);
            }else{
                dp[i][j]=0;
            }
        }
    }

    return ans;
}
int main(){

    string str1 = "abcde";
    string str2 = "abcdf";

    int n=str1.length();
    int m = str2.length();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    cout<<LCS_subStr(str1,str2,dp);

    return 0;
}