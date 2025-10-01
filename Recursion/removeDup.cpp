#include<iostream>
#include<vector>
using namespace std;
void remove(string str , int n , string &newStr, int i,vector<bool>&map ){
    if(i==n){
        return;
    }
    int idx =(int)str[i] - 'a';
    
    if(map[idx]){
        remove(str,n,newStr,i+1 , map);
    }else{
        map[idx] = true;   //set that idx to true before going to next call
        remove(str,n,newStr+=str[i] ,i+1, map);
        
    }
}
int main(){
    string str = "helloworld";
    vector<bool>map(26 ,false);
    string newStr = "";
    remove(str,str.length(),newStr,0,map);
    cout<<newStr<<endl;
    return 0;
}