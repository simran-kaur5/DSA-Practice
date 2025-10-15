#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        bool isCycle = false;
        ListNode* slow = head;
        ListNode* fast = head;

        // Detect cycle using Floyd's Tortoise and Hare
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                isCycle = true;
                break;
            }
        }

        if (isCycle) {
            slow = head;

            // Special case: cycle starts at head
            if (fast == slow) {
                while (fast->next != slow) {
                    fast = fast->next;
                }
                return slow;
            } else {
                // General case
                while (fast != slow) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }

        return nullptr; // No cycle
    }
};

int main() {
    // Create a linked list: 3 -> 2 -> 0 -> -4 -> cycle back to 3
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    // Create a cycle back to head
    head->next->next->next->next = head;

    Solution sol;
    ListNode* cycleStart = sol.detectCycle(head);

    if (cycleStart)
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle detected." << endl;

    // Note: Cannot safely delete nodes here due to cycle

    return 0;
}
