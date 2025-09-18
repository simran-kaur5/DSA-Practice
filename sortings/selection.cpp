#include <iostream>
using namespace std;
void print(int arr[] , int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void SelectionSort(int arr[] , int n){
    for(int i =0;i<n-1;i++){
        int minIdx = i;
        for(int j =i+1;j<n;j++){
            if(arr[j] < arr[minIdx]){
                minIdx =j;
            }
        }
        swap(arr[i] , arr[minIdx]);
    }
    print(arr , 5);
}


int main(){
    int arr [] = {5 , 3, 4 ,2, 9};
    SelectionSort(arr , 5);
}