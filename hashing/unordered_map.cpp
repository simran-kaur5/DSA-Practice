#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int>m;
    m["India"]=120;
    m["UK"]=23;
    m["Qwait"] = 98;
    m["Perth"] = 75;

    for(pair<string,int>p:m){
        cout<<"Country: "<<p.first<<" have population: "<<p.second;
        cout<<endl;
    }

    m.erase("India");

    if(m.count("India")){
        cout<<"India exists."<<endl;
    }else{
        cout<<"india does not exit"<<endl;
    }
    return 0;
}
