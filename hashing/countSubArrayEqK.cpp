#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int count(vector<int>&vec,int k){
    unordered_map<int,int>m;

    m[0]=1; //if first element is k
    int sum=0;
    int ans=0;
    for(int i=0;i<vec.size();i++){
        sum+=vec[i];

        if(m.count(sum-k)){
            ans+=m[sum-k];
        }

        if(m.count(sum)){
            m[sum]++;
        }else{
            m[sum]=1;
        }
    }
    return ans;
}
int main(){

    vector<int>vec = {10,2,-2,-20,10};
    cout<<"Number of Subarray Equal to k are: "<<count(vec,-10);
    return 0;
}