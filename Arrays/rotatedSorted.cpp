#include <iostream>
using namespace std;
int rs(int arr[], int st , int end , int target){
    while(end>=st){
        int mid = st + (end - st)/2;

        if(arr[mid] == target){
            return mid;
        }else{
            if(arr[st] < arr[mid] ){
                if(arr[mid] > target && arr[st] <= target) {
                    end = mid -1;
                }else{
                    st = mid+1;        
                }
            }else if(arr[mid] <= arr[end]){
                if(arr[mid]< target && arr[end] >= target) {
                    st = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }
    }
    return -1;
}

int main(){
    int arr [] = {4 , 5 , 6 , 7 , 0 , 1 , 2};
    int target = 4;
    cout<<rs(arr , 0 , 6 , 0);
}