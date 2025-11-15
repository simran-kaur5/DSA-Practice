#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
void printDistinct(vector<int>&vec){
    unordered_set<int>s;

    for(int i =0;i<vec.size();i++){
        s.insert(vec[i]);
    }

    for(auto i:s){
        cout<<i<<" ";
    }

    cout<<endl;
    cout<<"Number of distinct element in array is: "<<s.size()<<endl;
}
int main(){
    vector<int>vec = {2,3,4,5,2,3,5,6};

    printDistinct(vec);
}
