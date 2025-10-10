#include<iostream>
using namespace std;

int grid(int n , int row,int col,string ans){
    if(n-1==row && col == n-1 ){
        cout<<ans<<endl;
        return 1;
    }

    if(row==n || col ==n){
        return 0;
    }

    //if take move to down
    int val1 = grid(n,row+1,col,ans+"D");
    

    //if take move to right
    int val2 = grid(n,row,col+1,ans+"R");

    return val1 + val2;
}
int main(){
    int n = 3;
    string ans ="";
    int count = grid(n,0,0,ans);
    cout<<"Count of possible solutions: "<<count;
    return 0;
}