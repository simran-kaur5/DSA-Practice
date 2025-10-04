#include<iostream>
using namespace std;
int binarySearch(int arr[] , int st , int end ,int target){
    if(st>end){
        return -1;
    }
    int mid = st+(end-st)/2;

    if(arr[mid] == target){
        return mid;
    }else if(arr[mid] > target){
        binarySearch(arr , st , mid-1,target);
    }else{
        binarySearch(arr , mid+1, end,target);
    }
    
}
int main(){
    int arr[] = {1,4,7,9,10,15};
    cout<<binarySearch(arr,0,6,4);

    return 0;
}