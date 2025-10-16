#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LL
{
public:
    Node *head;
    Node *tail;
    LL()
    {
        head = NULL;
        tail = NULL;
    }

    // add node at front of LL
    void push_front(int val)
    {
        Node *newNode = new Node(val);

        // if linked list is empty
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val); // created node dynamically

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
        }
    }

    Node *printRemove(Node *head, int m, int n)
    {
        auto pre = head;

        while (pre)
        {
            for (int i = 0; i < m - 1 && pre; i++)
            {
                pre = pre->next;
            }

            auto curr = pre;

            for (int j = 0; j < n && curr; j++)
            {
                curr = curr->next;
            }

            if (curr != NULL)
            {
                pre->next = curr->next;
                pre = pre->next;
            }
            else
            {
                pre->next = NULL;
            }
        }
        return head;
    }
    // print Full linked List
    void print(Node *head)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{

    LL l1;
    l1.push_front(9);
    l1.push_front(7);
    l1.push_front(6);
    l1.push_front(4);
    l1.push_front(3);
    l1.push_front(8);
    l1.push_front(2);
    l1.push_front(1);
    l1.print(l1.head);
    Node *newhead = l1.printRemove(l1.head, 2, 2);
    l1.print(newhead);

    return 0;
}