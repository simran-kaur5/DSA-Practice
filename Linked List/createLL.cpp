#include<iostream>
using namespace std;
class Node{   //create individual nodes using class
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;   //in starting next of node is NULL
    }
};

class list{
    Node* head;
    Node* tail;

    list(){
        head = NULL;
        tail = NULL;
    }
};
int main(){   //basic to create a Linked List

    list l1();
    return 0;
}