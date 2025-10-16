#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLL
{
public:
    Node *head;
    Node *tail;

    DoublyLL()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Linked list is Empty." << endl;
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head=tail=NULL;
            return;
        }
        else
        {
            Node *nextNode = head->next;
            nextNode->prev = NULL;
            head->next = NULL;
            head = nextNode;
        }
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Linked list is Empty." << endl;
             head=tail=NULL;
            return;
        }

        if (head->next == NULL)
        {
            delete head;
        }
        else
        {
            Node *temp = head;
            while (temp->next!= NULL)
            {
                temp = temp->next;
            }
            // tail = temp;
            tail=tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{

    DoublyLL dll;
    dll.push_front(3);
    dll.push_front(2);
    dll.push_back(1);
    dll.print();
    dll.pop_front();
    dll.pop_back();
    dll.print();
    return 0;
}