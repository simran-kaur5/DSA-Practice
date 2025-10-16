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

    void deleteNode(int n){
        int size = 0;

        Node* temp = head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }

        if(n>size || n<=0){
            cout<<"Invalid n"<<endl;
            return;
        }

        int delIndex = size -n;
        

        if (delIndex == 1) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }

        int i =1;
        Node* nthNode = head;
        while(i<delIndex){
            nthNode = nthNode->next;
            i++;
        }
        Node* deleteNode = nthNode->next;
        nthNode -> next = deleteNode->next;
        delete deleteNode;
        
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
    l1.push_front(5);
    l1.push_front(4);
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    l1.print();
    l1.deleteNode(3);
    l1.print();
    return 0;
}