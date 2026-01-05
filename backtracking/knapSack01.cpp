#include<iostream>
#include<vector>
using namespace std;
int knapSack(vector<int>&val,vector<int>&w,int W,int n){
    if(W==0 || n==0){
        return 0;
    }

    int itemWt = w[n-1];
    int itemVal = val[n-1];
    if(itemWt<=W){ //possible to include exclude both
        int ans1 = knapSack(val,w,W-itemWt,n-1)+itemVal; //include

        int ans2 = knapSack(val,w,W,n-1); //exclude 

        return max(ans1,ans2);
    }else{

        return knapSack(val,w,W,n-1);
    }
}
int main(){

    vector<int>val = {15,14,10,45,30};
    vector<int>w = {2,5,1,3,4};
    int n = val.size();
    int W = 7;

    cout<<knapSack(val,w,W,n);
    return 0;
}