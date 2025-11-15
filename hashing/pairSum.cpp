#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
pair<int,int> findPair(vector<int>&vec,int target){
    unordered_map<int,int>m;
    for(int i =0;i<vec.size();i++){
        int x = vec[i];
        if(!m.empty() && m.find(target-x)!=m.end()){
            return {i,m[target-x]};
        }
        m[x]=i;
    }
    return {-1,-1};
}
int main(){
    vector<int>vec = {1,4,5,6,7,2};

    pair<int,int>p=findPair(vec,10);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}