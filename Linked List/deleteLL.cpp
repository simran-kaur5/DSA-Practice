#include<iostream>
using namespace std;
class Node{  
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;   //in starting next of node is NULL
    }
};

class list{
    public:
    Node* head;
    Node* tail;

    list(){
        head = NULL;
        tail = NULL;
    }

        void push_front(int val){
        Node* newNode = new Node(val);
        
        //if linked list is empty
        if(head== NULL){
            head = tail = newNode;
        }else{
            newNode -> next = head;
            head = newNode;
        }
    }

    void deleteFull(){
        Node* temp = head;
        head = NULL;
        while(temp!=NULL){
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

     void print(){
        Node* temp = head;

        if(head == NULL){
            cout<<"Linked list is empty"<<endl;
        }
        while(temp!= NULL){
            cout<<temp -> data <<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){   //basic to create a Linked List

    list l1;
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    l1.print();
    l1.deleteFull();
    l1.print();
    return 0;
}