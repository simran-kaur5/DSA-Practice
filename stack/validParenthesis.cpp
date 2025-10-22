#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isValid(string str){
    stack<char>s;

    for(int i =0;i<str.length();i++){    //TC -> O(n) , SC -> O(n)
        char ch = str[i];
        if(ch=='{' || ch == '(' || ch == '['){
            s.push(ch);
        }else{
            if(s.empty()){
                return false;
            }else{
                if(ch == ']' && s.top() == '['){
                    s.pop();
                }else if(ch == '}' && s.top() == '{'){
                    s.pop();
                }else if(ch == ')' && s.top() == '('){
                    s.pop();
                }else{
                    return false;
                }
            }
        }
    }
    return s.empty();
}
int main(){
    string str1 = "{(]]}";   //invalid
    string str2 = "{([]())}";    //valid

    cout<<isValid(str2);


    return 0;
}