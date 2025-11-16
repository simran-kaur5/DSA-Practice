#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;
void tickets(unordered_map<string,string>&m){
    unordered_set<string>to;

    string start = "";
    for(pair<string,string>p:m){
        to.insert(p.second);
    }

    for(pair<string,string>p:m){
        if(to.find(p.first)==to.end()){
            start = p.first;//start of journey
        }
    }

    cout<<start<<"->";
    while(m.count(start)){
        start = m[start];
        cout<<start<<"->";
    }

    cout<<"Destination";
}
int main(){

    unordered_map<string,string>m;
    m["Chennai"]="Bengaluru";
    m["Mumbai"] = "Delhi";
    m["Goa"]="Chennai";
    m["Delhi"] = "Goa";

    tickets(m);
    return 0;
}