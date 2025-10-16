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
Node* merge(Node*left , Node* right){
    LL list;

    Node* i = left;
    Node* j =right;
    while(i!=NULL && j!=NULL){
        if(i->data < j->data){
             list.push_back(i->data);
             i = i->next;
        }else{
            list.push_back(j->data);
            j=j->next;
        }
    }

    while(i!=NULL){
        list.push_back(i->data);
        i = i->next;
    }
    while(j!=NULL){
        list.push_back(j->data);
        j=j->next;
    }

    return list.head;
}

Node* split(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* prev = NULL;
    Node* slow = head;
    Node* fast = head;


    while(fast!=NULL && fast->next !=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev!=NULL){
        prev->next = NULL;
    }

    return slow;
}
Node* mergeSort(Node* head){
        if( head==NULL || head -> next==NULL){
            return head;
        }

    Node* rightHead = split(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left,right);

   }

    //print Full linked List
     void print(Node* head){
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
    l1.push_front(6);
    l1.push_front(5);
    l1.push_front(10);
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    Node* newHead = l1.mergeSort(l1.head);
    l1.print(newHead);
    
    return 0;
}