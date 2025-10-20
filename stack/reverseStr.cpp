#include<iostream>
#include<stack>
using namespace std;
string reverse(string str){
    string newStr = "";
    stack<char>s;

    int n=str.length();
    for(int i =0;i<n;i++){        // TC -> O(n)  , SC -> O(n)  as we used extra stack to reverse the string
        s.push(str[i]);
    }

    while(!s.empty()){    
        newStr+=s.top();
        s.pop();
    }

    return newStr;
}
int main(){
    
    string str = "Hello World";
    cout<<"Reversed String: "<<reverse(str);

    return 0;
}