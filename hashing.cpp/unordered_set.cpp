#include<iostream>
#include<unordered_set>
using namespace std;
int main(){

    unordered_set<int>s;

    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(9);

    if(s.find(4)!=s.end()){
        cout<<"4 exists."<<endl;
    }else{
        cout<<"Does not exist.."<<endl;
    }
    for(auto el:s){
        cout<<el<<" ";
    }
    cout<<endl;

    return 0;
}