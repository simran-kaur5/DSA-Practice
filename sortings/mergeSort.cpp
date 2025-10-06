#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&arr , int st , int end , int mid){
    int i = st;
    int j = mid+1;

    vector<int>temp;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }

    while(i<=mid) temp.push_back(arr[i++]);
    while(j<=end) temp.push_back(arr[j++]);

    //vector  -> org arr
    for(int i = st,x=0;i<=end;i++){
        arr[i] = temp[x++];
    }
}

void mergeSort(vector<int>&arr , int st , int end){
    if(end<=st){
        return;
    }

    int mid = st+ (end-st)/2;

    mergeSort(arr , st , mid);
    mergeSort(arr , mid+1 , end);
    merge(arr,st,end,mid);

}

void print(vector<int>&arr){
    for(int x:arr){
        cout<<x<<" ";
    }
}
int main(){
    vector<int>arr = {2,8,3,9,5,4};
    int n = 6;
    cout<<"Array before sorting: ";
    print(arr);
    mergeSort(arr , 0 , n-1);
    cout<<"Array after sorting: ";
    print(arr);
    return 0;
}