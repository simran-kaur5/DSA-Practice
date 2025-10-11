#include<iostream>
#include<vector>
using namespace std;
void bfs(int pos,int l, vector<vector<char>>&letter, string dig,string ans){
    if(pos == l){
        cout<<ans<<endl;
        return;
    }
    vector<char>lt = letter[dig[pos]-'0'];
    for(int i=0;i<lt.size();i++){
        bfs(pos+1,l,letter,dig,ans+lt[i]);
    }
}

void letterCom(vector<vector<char>>&letter, string dig){
    if(dig.length()==0){
        cout<<"";
        return;
    }
    string ans ="";
    bfs(0,dig.length(),letter,dig,ans);
}
int main(){

    vector<vector<char>>L = { {},{} ,{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    string digits = "27";
    letterCom(L,digits);
    return 0;
}