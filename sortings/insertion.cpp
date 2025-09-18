#include <iostream>
using namespace std;
void print(int arr[] , int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void print(char arr[] , int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void insertionSort(int arr[] , int n){
    for(int i =1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
    print(arr , 5);
}

//homework  -> in descending order


// char ch = {'f','b','a','e','c','d'};
void sort(char ch[] , int n){
    for(int i =1;i<n ;i++){
        char c = ch[i];
        int prev = i-1;

        while(prev>=0 && ch[prev] < c){
            ch[prev+1] = ch[prev];
            prev--;
        }
        ch[prev+1] =c;

    }
    print(ch , 6);
}



int main(){
    char ch[] = {'f','b','a','e','c','d'};
    sort(ch , 6);
}