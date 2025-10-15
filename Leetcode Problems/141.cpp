#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class (like LeetCode submission)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; // cycle detected
            }
        }
        return false; // no cycle
    }
};

// Helper: Create linked list from array (no cycle)
ListNode* createList(const int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper: Print linked list (stops after 20 nodes to avoid infinite loop)
void printList(ListNode* head) {
    int count = 0;
    while (head && count < 20) {
        cout << head->val << " -> ";
        head = head->next;
        count++;
    }
    if (head) cout << "... (cycle detected?)";
    else cout << "NULL";
    cout << endl;
}

int main() {
    // Example 1: Linked list without cycle
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1, 5);

    cout << "Linked List 1: ";
    printList(head1);

    Solution sol;
    bool result1 = sol.hasCycle(head1);
    cout << "Cycle detected? " << (result1 ? "Yes" : "No") << endl;

    // Example 2: Linked list with a cycle
    ListNode* head2 = createList(arr1, 5);
    head2->next->next->next->next->next = head2->next->next; // create cycle at node 3

    cout << "\nLinked List 2: ";
    printList(head2); // will stop after 20 nodes

    bool result2 = sol.hasCycle(head2);
    cout << "Cycle detected? " << (result2 ? "Yes" : "No") << endl;

    return 0;
}
