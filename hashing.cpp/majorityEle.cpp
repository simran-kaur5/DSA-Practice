#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void majority(vector<int>&vec){
    unordered_map<int,int>m;
    int n =vec.size();

    for(int i=0;i<vec.size();i++){
        if(m.count(vec[i])){
            m[vec[i]]++;
        }else{
            m[vec[i]] =1;
        }
    }

    for(pair<int,int>p:m){
        if(p.second >= n/3){
            cout<<p.first<<" ";
        }
    }
    cout<<endl;
}
int main(){

    vector<int>vec = {3,1,2,2,2,2,2,5,2,2,1,6,1,1,1,1};
    majority(vec);
    return 0;
}