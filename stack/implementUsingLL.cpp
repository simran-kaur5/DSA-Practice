#include<iostream>
using namespace std;
template<class D>
class Node{
    public:
    D data;
    Node* next;

    Node(D val){
        data = val;
        next = NULL;
    }
};
template<class T>

class Stack{
     Node<T>* head;  // Use Node<T> not Node
    Node<T>* tail;
    public:
    Stack(){
    head = tail = NULL;
    }

    
    void push(T val){   //O(1)
         Node<T>* newNode = new Node<T>(val);
        if(isEmpty()){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void pop(){       //O(1)
        if(isEmpty()){
            cout<<"Nothing to pop out"<<endl;
            return;
        }else{
            Node<T>* temp = head;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }

    T top(){         //O(1)
        if(!isEmpty()){
            return head->data;
        }
    }

    bool isEmpty(){        //O(1)
        return head == NULL;
    }
};
int main(){

    Stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}