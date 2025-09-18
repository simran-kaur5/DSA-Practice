#include <iostream>
#include <climits>
using namespace std;
void print(int arr[] , int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void countingSort(int arr[] , int n){
    int minElement = INT_MAX;
    int maxElement = INT_MIN;
    int freq [10000];   //taking size of array so big bcz its not dynamic
    for(int i = 0;i<n;i++){  // find range of freq array
        minElement = min(minElement , arr[i]);
        maxElement = max(maxElement  , arr[i]);
    }

    for(int i = 0 ;i<n;i++){
        freq[arr[i]]++;
    }
    
    int j =0;
    for(int i = minElement;i<=maxElement;i++){
        while(freq[i] > 0 ){
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }
    print(arr , 10);
}


int main(){
    int arr [] = {1,3,2,5,2,5 , 3, 4 ,2, 9};
    countingSort(arr , 10);
    return 0;
}