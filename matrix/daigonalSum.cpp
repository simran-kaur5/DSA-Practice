#include <iostream>
using namespace std;
void daigonalSum(int n , int mat[][4]){
    int sum=0;
    for(int i =0;i<n;i++){
        sum+=mat[i][i];
    }
    for(int i = 0;i<n;i++){
        if(i==n-i-1){
            continue;
        }
        sum+=mat[i][n-i-1];
    }
    cout<<sum;
}
int main(){
    int mat[4][4]={
        {1 , 5,6,7},
        {8,2,9,10},
        {11,12,3,13},
        {14,15,16,4}
    };
    int n =4;
    daigonalSum(n,mat);
}