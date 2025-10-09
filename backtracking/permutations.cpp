#include<iostream>
using namespace std;
void permutation(string str , string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    int n = str.length();
    for(int i=0;i<n;i++){
        char ch = str[i];

        string nextStr = str.substr(0,i) + str.substr(i+1);

        permutation(nextStr, ans+ch);
    }
}
int main(){
    string str = "abc";
    string ans = "";
    permutation(str,ans);
    return 0;
}