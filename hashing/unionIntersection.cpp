#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void unions(vector<int>&vec1,vector<int>&vec2){
    unordered_set<int>s;
    cout<<"union of two arrays is: ";
    for(int i =0;i<vec1.size();i++){
        if(s.find(vec1[i])==s.end()){
            cout<<vec1[i]<<" ";
            s.insert(vec1[i]);
        }
    }

    for(int i =0;i<vec2.size();i++){
        if(s.find(vec2[i])==s.end()){
            cout<<vec2[i]<<" ";
            s.insert(vec2[i]);
        }
    }
    cout<<endl;
}

void interSection(vector<int>&vec1,vector<int>&vec2){
    unordered_set<int>s;
    cout<<"InterSection of two arrays is: ";
    for(int i =0;i<vec1.size();i++){
        if(s.find(vec1[i])==s.end()){
            s.insert(vec1[i]);
        }
    }

    for(int i =0;i<vec2.size();i++){
        if(s.find(vec2[i])!=s.end()){
            cout<<vec2[i]<<" ";
            s.erase(vec2[i]);
        }

    }
    cout<<endl;
}
int main(){

    vector<int>vec1 = {7,3,9};
    vector<int>vec2 = {6,3,9,2,9,4};

    unions(vec1,vec2);
    interSection(vec1,vec2);
    return 0;
}