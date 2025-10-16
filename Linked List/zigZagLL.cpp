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
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    Node* split(Node* head){
        Node* prev = NULL;
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev) prev->next = NULL; // safe check
        return slow;
    }

    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void zigZag(Node* head){
        if(!head || !head->next) return;

        Node* rightHead = split(head);
        Node* newHead = reverse(rightHead);

        Node* left = head;
        Node* right = newHead;
        Node* tail = NULL;

        while(left != NULL && right != NULL){
            Node* nextLeft = left->next;
            Node* nextRight = right->next;

            left->next = right;
            right->next = nextLeft;

            tail = right;
            left = nextLeft;
            right = nextRight;
        }

        if(tail) tail->next = right; // safe connection
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    LL l1;
    l1.push_front(5);
    l1.push_front(4);
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);

    cout << "Original List: ";
    l1.print();

    l1.zigZag(l1.head);

    cout << "Zig-Zag List: ";
    l1.print();

    return 0;
}
