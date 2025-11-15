#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool valid(string str1,string str2){

    if(str1.length()!=str2.length()){
        return false;
    }
    unordered_map<char,int>m;

    for(char ch:str1){
        m[ch]++;
    }

    for(int i =0;i<str2.length();i++){
        if(m.count(str2[i])==0){  //if str2 have some more chars
            return false;
        }else{
        m[str2[i]]--;
        if(m[str2[i]]==0){
            m.erase(str2[i]);
        }
    }
    }

return m.empty();//not zero means str1 have more chars 
}
int main(){

    string str1 = "care";
    string str2 = "race";

    if(valid(str1,str2)){
        cout<<"Both are Valid Anagrams."<<endl;
    }else{
        cout<<"Not valid."<<endl;
    }
    return 0;
}