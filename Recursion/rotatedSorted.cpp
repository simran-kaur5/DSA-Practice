#include<iostream>
using namespace std;
int rotatedSorted(int nums[] ,int st , int end , int target){
    if(st>end){
        return -1;
    }

    int mid = st+(end-st)/2;
    if(nums[mid] == target){
        return mid;
    }
    if(nums[st] <= nums[mid]){   // on line 1
        if(nums[st] <=target && nums[mid] >= target){
            return rotatedSorted(nums , st ,mid-1,target );   //search in left half
        }else{
            return rotatedSorted(nums , mid+1 ,end,target );   //search in right half
        }
    }else{  //on line 2
        if(nums[mid] <= target && nums[end] >= target){
            return rotatedSorted(nums,mid+1,end,target);  //search in right half
        }else{
            return rotatedSorted(nums,st,mid-1,target);  //search in  half
        }
    }
}
int main(){
    int arr[] = {4,5,6,7,0,1,2};
    int n =7;
    cout<<rotatedSorted(arr , 0 , n-1,0);
    return 0;
}