#include<iostream>
#include<vector>
using namespace std;
template <class T>   //using templates of class because stack can be of any data type
class stack{
    public:
    vector<T>vec;
    void push(T val){     //O(1)
        vec.push_back(val);
    }

    void pop(){
        if(isEmpty()){      //O(1)
            cout<<"Stack is empty nothing to pop."<<endl;  //underflow
            return;
        }
        vec.pop_back();
    }

    int top(){
        if(isEmpty()){    //O(1)
            cout<<"Stack is empty nothing to display."<<endl;
            return -1;
        }
        return vec[vec.size()-1];
    }

    bool isEmpty(){     //O(1)
        return vec.size()==0;
    }

};
int main(){
    stack<int>s;   //the type we want
    s.push(1);
    s.push(2);
    s.push(3);
    
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}