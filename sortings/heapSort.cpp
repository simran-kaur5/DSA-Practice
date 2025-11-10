#include<iostream>
#include<vector>
using namespace std;

void heapify(int i,vector<int>&vec,int n){
    if(i>=n){
        return;
    }
    int leftIdx = 2*i+1;
    int rightIdx = 2*i+2;
    int maxIdx =i;

    if(leftIdx<n && vec[leftIdx]>vec[maxIdx]){
        maxIdx=leftIdx;
    }
    if(rightIdx <n && vec[rightIdx]>vec[maxIdx]){
        maxIdx=rightIdx;
    }
  
    if(i!=maxIdx){
        swap(vec[i],vec[maxIdx]);
        heapify(maxIdx,vec,n);
    }
}

void heapSort(vector<int>&vec){
    int n = vec.size();
    for(int i = n/2-1;i>=0;i-- ){
        heapify(i,vec,n);
    }

    for(int i = n-1;i>=0;i--){
        swap(vec[0],vec[i]);
        heapify(0,vec,i);
    }
}
int main(){

    vector<int> vec = {1,4,2,5,3};
    heapSort(vec);

    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    return 0;
}