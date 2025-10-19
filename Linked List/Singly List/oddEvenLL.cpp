#include <iostream>
using namespace std;

// Define a Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* oddEven(Node*head){
    Node*temp = head;
    

    Node *evenHead = NULL, *evenTail = NULL;
    Node *oddHead = NULL, *oddTail = NULL;

    while(temp!=NULL){
        Node* nextNode = temp->next; // save next node
            // detach current node
        temp->next = NULL;   
        if(temp->data%2==0){
            if(evenHead==NULL){
                evenHead = evenTail = temp;

            }else{
                evenTail->next = temp;
                evenTail = temp;
            }
        }else{
            if(oddHead==NULL){
                oddHead = oddTail = temp;
            }else{
                oddTail->next =temp;
                oddTail = temp;
            }
            
        }
        temp = nextNode;
    }
    if(evenHead){
    evenTail->next = oddHead;
    return evenHead;
    }
    return oddHead;
}
int main() {
    // Creating nodes
    Node* head = new Node(8);
    head->next = new Node(12);
    head->next->next = new Node(10);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next = new Node(6);

    // Print the linked list
    printList(head);

    Node* newH =oddEven(head);
    printList(newH);

    return 0;
}
