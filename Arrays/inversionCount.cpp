#include<iostream>
#include<vector>
using namespace std;
int merge(vector<int>&arr , int st , int end , int mid){
    int i = st;
    int j = mid+1;
    int inversion = 0;
    vector<int>temp;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }else{
            inversion+=(mid-i+1);
            temp.push_back(arr[j++]);
        }
    }

    while(i<=mid) temp.push_back(arr[i++]);
    while(j<=end) temp.push_back(arr[j++]);

    //vector  -> org arr
    for(int i = st,x=0;i<=end;i++){
        arr[i] = temp[x++];
    }
    return inversion;
}

int mergeSort(vector<int>&arr , int st , int end){
    int inversion = 0;
    if(end>st){
      

    int mid = st+ (end-st)/2;
    
    inversion += mergeSort(arr , st , mid);
    inversion += mergeSort(arr , mid+1 , end);
    inversion += merge(arr,st,end,mid);
    }
    return inversion;
}

void print(vector<int>&arr){
    for(int x:arr){
        cout<<x<<" ";
    }
}
int main(){
    vector<int>arr = {2,8,3,9,5,4};
    int n = 6;
    int count = mergeSort(arr , 0 , n-1);
    cout<<count;
    return 0;
}