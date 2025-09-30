#include<iostream>
using namespace std;
int last(int arr[] , int n , int i, int target){
    if(i==n){
        return -1;
    }
    int idx = last(arr , n , i+1, target);
    if(idx==-1){
    if(arr[i] ==target){
        return i;
    }
}
}
int main(){
    int arr[] = {1,3,4,5,3};
    int n =5;
    cout<<last(arr, n , 0,3);
    return 0;
}