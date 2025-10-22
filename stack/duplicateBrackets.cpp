#include<iostream>
#include<stack>
using namespace std;
bool duplicate(string str){
    stack<char>s;
    
    for(int i =0;i<str.length();i++){
        char ch = str[i];
        if(ch!=')'){
            s.push(ch);
        }else{
            if(s.top()=='('){ //we are not checking that stack is empty or not ???? because it is given that string is valid
                return true; //we return true if opening bracket is on top which means there is no content between that parenthesis -> which means its duplicate
            }else{
                while(s.top()!='('){
                    s.pop();  // remove chars between both brackets
                }
                s.pop(); // also pop the opening bracket
            }
        }
    }
return false;  //no duplicate
}
int main(){
    string str1 = "((a+b))";  //true
    string str2 = "((a+b)+(a+b))"; //false

    cout<<duplicate(str1)<<endl;   //true
    cout<<duplicate(str2)<<endl;   //false
    return 0;
}