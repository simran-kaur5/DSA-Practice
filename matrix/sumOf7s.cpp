#include <iostream>
using namespace std;
int sum(int arr[][3] , int r , int c){
    int sum=0;
    for(int i =0;i<r;i++){
        for(int j =0;j<c;j++){
            if(arr[i][j]==7){
                sum+=arr[i][j];
            }
        }
    }
    return sum;
}
int main(){
    int arr[2][3]={
        {4 , 7,8},
        {8,8,7}
    };
    cout<<sum(arr , 2 , 3);
    return 0;
}