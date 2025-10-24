#include<iostream>
#include<stack>
using namespace std;

class MyQueue {

public:
    stack<int>s1;
    stack<int>s2;
    
    void push(int x) {
        if(empty()){
            s1.push(x);
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);

            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    int pop() {
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
       return s1.empty();
    }
};
int main(){
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.peek()<<" ";
        q.pop();
    }

    return 0;
}