#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class
class Solution {
public:
    // Detect the start of the cycle (LeetCode 142)
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Detect cycle using Floyd's Tortoise and Hare
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Cycle detected; find start of cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr; // No cycle
    }
};

int main() {    //copy full class to submit on leetcode
    // Creating a linked list: 3 -> 2 -> 0 -> -4 -> 2 (cycle)
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Creating a cycle: last node points to second node
    head->next->next->next->next = head->next;

    Solution sol;
    ListNode* cycleStart = sol.detectCycle(head);

    if (cycleStart)
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle detected." << endl;

    // Note: Cannot safely delete nodes here due to cycle

    return 0;
}
