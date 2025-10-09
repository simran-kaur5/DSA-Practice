#include<iostream>
using namespace std;


void subsets(string str , string ans){
    if(str.length() == 0){   //Base Case
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];

    //take choice to add in answer
    subsets(str.substr(1,str.length()-1), ans+ch);

    //take choice not to add in answer
    subsets(str.substr(1,str.length()-1) , ans);
}

int main(){
    string str = "abc";
    string ans = "";
    subsets(str,ans);
    return 0;
}