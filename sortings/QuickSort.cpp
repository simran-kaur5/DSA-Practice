#include<iostream>
using namespace std;
int partition(int arr[] ,int st , int end){
    int i = st-1;   //less values 
    int j = st;
    int p = arr[end];
    while(j<end){
        if(arr[j] <= p){
            i++;
            swap(arr[j] , arr[i]);
        }j++;
    }
    i++;
    swap(arr[i] , arr[end]);
    
    return i;   //pivot index
}

void quick(int arr[],int st, int end){
    if(st>=end){
        return;
    }
    int pivot = partition(arr,st,end);

    quick(arr,st,pivot-1);  //left half
    quick(arr,pivot+1,end); //right half
}

void print(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int arr[] = {6,3,7,5,2,4};
    int n = 6;
    cout<<"Array before sorting: ";
    print(arr,n);
    quick(arr,0,n-1);
    cout<<"Array after sorting: ";
    print(arr,n);
    return 0;

}