#include<iostream>
using namespace std;
int firstOccur(int arr[] , int n , int i, int target){
    if(i==n){
        return -1;
    }
    if(arr[i] == target){
        return i;
    }
    return firstOccur(arr , n, i+1, target);
}
int main(){
    int arr [] = {1,2,3,4,5,3};
    cout<<firstOccur(arr , 6 , 0,3);
    return 0;
}