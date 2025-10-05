#include<iostream>
using namespace std;
void allOccur(int arr[],int key,int i , int n) {
    if(i==n){
        return;
    }
    if(arr[i] == key){
        cout<<i<<" ";
    }

    allOccur(arr,key,i+1,n);
}
int main(){
    int arr[] = {3,2,4,5,6,2,7,2,2};
    int key =2;
    allOccur(arr,key,0,9);
    return 0;
}