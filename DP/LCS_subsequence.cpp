#include<iostream>
#include<vector>
using namespace std;

int longestSubMemo(string str1 , string str2,vector<vector<int>>dp){
    if(str1.length()==0 || str2.length()==0){
        return 0;
    }

    int n = str1.length();
    int m = str2.length();

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if(str1[n-1]==str2[m-1]){
        dp[n][m] = 1 + longestSubMemo(str1.substr(0,n-1),str2.substr(0,m-1),dp);
    }else{
        int ans1 = longestSubMemo(str1.substr(0,n-1),str2,dp);
        int ans2 = longestSubMemo(str1,str2.substr(0,m-1),dp);
        dp[n][m] = max(ans1,ans2);
    }

    return dp[n][m];
}

int longestSubTab(string str1 , string str2,vector<vector<int>>dp){

    int n = str1.length();
    int m = str2.length();

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n][m];

}
int main(){

    string str1 = "abcde";
    string str2 = "abcdeg";

    int n = str1.length();
    int m = str2.length();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    cout<<longestSubTab(str1,str2,dp);

    return 0;
}