#include<iostream>
#include<stack>
using namespace std;
void pushBottom(stack<int>&s , int val){    
    if(s.size()==0){
        s.push(val);
        return;
    }
        int temp = s.top();   
        s.pop();
        pushBottom(s,val);
        s.push(temp);   
}
void reverse(stack<int>&s){
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverse(s);
    pushBottom(s,temp);

}
int main(){
        //Tc -> O(n^2)  , SC -> O(n)
    stack<int>s;
    s.push(3);
    s.push(2);
    s.push(1);
    reverse(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}