#include <iostream>
#include<unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


Node* pointOfInterSection(Node*head1,Node*head2){
    unordered_set<Node*>s;

    Node* temp1 = head1;
    Node*temp2 = head2;
    while(temp1!=NULL){
        s.insert(temp1);
        temp1 = temp1->next;
    }

    while(temp2!=NULL){
        if(s.find(temp2)!=s.end()){
            return temp2;
        }
        temp2= temp2->next;
    }
    return NULL;
}
// Function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create first linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    // Create second linked list: 9 -> 10
    Node* head2 = new Node(9);
    head2->next = new Node(10);

    // Make the second list intersect the first list at node 3
    head2->next->next = head1->next->next; // 10 -> 3

    // Print both lists
    cout << "Linked List 1: ";
    printList(head1);

    cout << "Linked List 2: ";
    printList(head2);
    
    Node* ans = pointOfInterSection(head1,head2);

    if(ans==NULL){
        cout<<"No any point of interSection exits."<<endl;
    }else{
        cout<<"point of interSection: "<<ans->data<<endl;
    }

    return 0;
}
