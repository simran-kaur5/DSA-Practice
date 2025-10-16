#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class
class Solution {
public:
    // Split list into two halves
    ListNode* split(ListNode* head){
        if(!head) return nullptr;
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev) prev->next = nullptr;
        return slow;
    }

    // Reverse a linked list
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Reorder list in zig-zag fashion
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        ListNode* left = head;
        ListNode* right = reverse(split(head));
        ListNode* tail = nullptr;

        while(left && right){
            ListNode* nextLeft = left->next;
            ListNode* nextRight = right->next;

            left->next = right;
            right->next = nextLeft;

            tail = right;
            left = nextLeft;
            right = nextRight;
        }

        if(tail) tail->next = right;
    }
};

// Helper function to print linked list
void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    // Reorder list
    Solution sol;
    sol.reorderList(head);

    cout << "Zig-Zag List: ";
    printList(head);

    return 0;
}
