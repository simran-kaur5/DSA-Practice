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

    void search(int key){   //TC -> O(n)
        if(head == NULL){
            cout<<"Linked List is Empty."<<endl;
            return;
        }
        if(head->data == key){
            cout<<"Found the key";
            return;
        }else{
            Node* temp = head;
            while(temp!=NULL){
                if(temp->data==key){
                    cout<<"Key found."<<endl;
                    return;
                }
                temp = temp->next;
            }
            if(temp==NULL){
                cout<<"Key not found"<<endl;
            }
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
int main(){   

    list l1;
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    l1.print();
    l1.search(2);
    
    return 0;
}