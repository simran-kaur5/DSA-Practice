#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool ispos(vector<int>&vec,int c,int n,int mid){
    int lastPos = vec[0];
    int cow=1;

    for(int i=1;i<n;i++){
        if((vec[i]-lastPos)>=mid){
            lastPos = vec[i];
            cow++;
        }

        if(cow==c){
            return true;
        }
    }

    return false;
}

int main(){

    vector<int>vec = {1,2,8,4,9};
    int n = vec.size();
    int cow =3;

    sort(vec.begin(),vec.end());

    int st = 1,end = vec[n-1] - vec[0];
    int ans =-1;

    while(end>=st){
        int mid = st + (end-st)/2;

        if(ispos(vec,cow,n,mid)){
            ans=mid;
            st = mid+1;
        }else{
            end = mid-1;
        }
    }

    cout<<ans;

    return 0;
}