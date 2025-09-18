#include <iostream>
using namespace std;
void print(int arr[] , int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void bubbleSort(int arr[] , int n){
    for(int i = 0;i<n-1;i++){
        for(int j = 0 ;j<n-i-1;j++){
            if(arr[j] >arr[j+1]){
            swap(arr[j] , arr[j+1]);
            }
        }
    }
    print(arr , 5);
}


int main(){
    int arr [] = {5 , 3, 4 ,2, 9};
    bubbleSort(arr , 5);
}