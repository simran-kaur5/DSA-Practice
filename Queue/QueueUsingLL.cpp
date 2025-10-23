#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    Node* head;
    Node* tail;

    public:
    Queue() {  // Constructor
        head = tail = NULL;
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(isEmpty()){
            head = tail = newNode;
        }else{
            tail-> next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty.."<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int front(){
        if(isEmpty()){
            cout<<"Queue is empty.."<<endl;
            return -1;
        }

        return head->data;
    }

    bool isEmpty(){
        return head==NULL;
    }
};
int main(){

    Queue q;
    q.push_back(3);
    q.push_back(2);
    q.push_back(1);

    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}