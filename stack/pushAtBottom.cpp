#include<iostream>
#include<stack>
using namespace std;
void pushBottom(stack<int>&s , int val){    //TC -> O(n)
    if(s.size()==0){
        s.push(val);
        return;
    }
        int temp = s.top();   //save top value of stack to push it again
        s.pop();   //pop the top
        pushBottom(s,val);
        s.push(temp);   //while bactracking push the popped value
}
int main(){

    stack<int>s;

    s.push(3);
    s.push(2);
    s.push(1);
    int val = 4;

    pushBottom(s,val);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }


    return 0;
}