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


    //add node at front of LL
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


    //add node at last
    void push_back(int val){
        Node* newNode = new Node(val);   //created node dynamically

        if(head == NULL){
            head = tail = newNode;
        }else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp -> next = newNode;
            newNode->next = NULL;
        }
    }

    //delete node from front
    void pop_front(){
        if(head==NULL){
            cout<<"Nothing to pop";
            return;
        }
        if(head->next == NULL){
            delete head; 
        }else{
            Node* temp = head;
            head = head -> next;
            temp->next = NULL;
            delete temp;
        }
    }
    

    //delete Node from back
    void pop_back(){
        if(head == NULL){
            cout<<"Nothing to delete";
            return;
        }

        if(head->next==NULL){
            delete head;
        }else{
            Node* temp = head;
            while(temp->next->next!=NULL){
                temp = temp->next;
            }
            delete temp -> next;  //create node dyanmically and also deleted dynamically
            temp->next = NULL;
        }

    }
    //print Full linked List
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
    l1.push_back(4);
    l1.print();
    l1.pop_front();
    l1.print();
    l1.pop_back();
    l1.print();
    
    return 0;
}