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

    int helper(Node* temp, int key){
        if(temp==NULL){
            return -1;
        }
        if(temp->data==key){
            return 0;
        }
        int idx = helper(temp->next,key);

        if(idx==-1){
            return -1;
        }
        return idx+1;

    }

    int search(int key){
        return helper(head,key);
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
int main(){   

    list l1;
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    l1.print();
    
    cout<<l1.search(2);
    return 0;
}