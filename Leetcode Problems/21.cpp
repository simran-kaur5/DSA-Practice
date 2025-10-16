#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode* newList = &dummy;
        ListNode* i = list1;
        ListNode* j = list2;

        while(i != nullptr && j != nullptr) {
            if(i->val > j->val) {
                newList->next = j;
                j = j->next;
            } else {
                newList->next = i;
                i = i->next;
            }
            newList = newList->next;
        }

        // attach remaining nodes
        if(i != nullptr) newList->next = i;
        if(j != nullptr) newList->next = j;

        return dummy.next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create first sorted list: 1->3->5
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    // Create second sorted list: 2->4->6
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    Solution sol;
    ListNode* mergedHead = sol.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}
