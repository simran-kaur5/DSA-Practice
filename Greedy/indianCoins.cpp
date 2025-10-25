#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minCoins(vector<int>coins,int V){
    sort(coins.begin(),coins.end());

    int ans =0;
    for(int i =coins.size()-1;i>=0,V>0;i--){
        if(V>=coins[i]){
            ans+= (V/coins[i]);  //how many notes to add 
            V%=coins[i];   //how much amt left to pay
        }
    }
    return ans;
}
int main(){

    vector<int>coins = {1,2,5,10,20,50,100,500,2000};
    int n = 9;
    int V = 590;
    cout<<"Min coins to pay: "<<minCoins(coins,V);
    return 0;
}