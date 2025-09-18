#include <iostream>
using namespace std;
int SumOfSecond(int arr[][3] , int r){
    int sum=0;
    for(int i =0;i<r;i++){
        sum+=arr[1][i];
    }
    return sum;
}
int main(){
    int arr[3][3]={
        {1,4,9},
        {11,4,3},
        {2,2,3}
    };
    cout<<SumOfSecond(arr , 3);
    return 0;
}