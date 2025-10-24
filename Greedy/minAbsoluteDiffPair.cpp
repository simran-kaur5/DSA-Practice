#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minAb(vector<int>&a,vector<int>&b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int n = a.size();

    vector<pair<int,int>>min(n,make_pair(0,0));

    for(int i =0;i<a.size();i++){
        min[i]=make_pair(a[i],b[i]);
    }

    int Sum =0;

    for(int i =0;i<a.size();i++){
        Sum+=abs(min[i].first-min[i].second);
    }

    cout<<"Min Absolute Differnce: "<<Sum<<endl;
}
int main(){
    vector<int>a = {4,1,8,7};
    vector<int>b = {2,3,6,5};

    minAb(a,b);
    return 0;
}
