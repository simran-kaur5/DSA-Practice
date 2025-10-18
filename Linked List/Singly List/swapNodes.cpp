
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

    // add node at last
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

    Node *swapNodes(int x, int y)
    {
        Node *temp = head;
        Node *prevX = NULL;
        Node *prevY = NULL;

        while (temp != NULL && temp->data != x)
        {
            prevX = temp;
            temp = temp->next;
        }
        Node *currX = temp;
        temp = head;

        while (temp != NULL && temp->data != y)
        {
            prevY = temp;
            temp = temp->next;
        }
        Node *currY = temp;

        if (currX == NULL || currY == NULL)
        {
            return head;
        }

        Node *xNext = currX->next;
        currX->next = currY->next;
        currY->next = xNext;

        if (prevX != nullptr)
            prevX->next = currY;
        else
            head = currY;

        if (prevY != nullptr)
            prevY->next = currX;
        else
            head = currX;

        return head;
    }

    // print Full linked List
    void print()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout <<temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{

    LL l1;
    l1.push_front(4);
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);

    int x = 2, y = 4;
    Node *h = l1.swapNodes(x, y);
    l1.print();

    return 0;
}