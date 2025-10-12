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

class LL{
public:
    Node* head;
    Node* tail;
    LL(){
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
    void print(){
        Node* temp = head;

        while(temp!= NULL){
            cout<<temp -> data <<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){

    LL l1;
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    l1.print();
    
    return 0;
}