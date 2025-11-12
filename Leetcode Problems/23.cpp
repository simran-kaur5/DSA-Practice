#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //Correct min-heap
        priority_queue<int, vector<int>, greater<int>> pq;

        // Push all node values
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp != NULL) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        // Create merged list
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (!pq.empty()) {
            temp->next = new ListNode(pq.top());
            pq.pop();
            temp = temp->next;
        }

        return dummy->next;
    }
};

// Helper function to create a linked list from vector
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example input: 3 sorted linked lists
    vector<int> arr1 = {1, 4, 5};
    vector<int> arr2 = {1, 3, 4};
    vector<int> arr3 = {2, 6};

    // Convert to linked lists
    ListNode* l1 = createList(arr1);
    ListNode* l2 = createList(arr2);
    ListNode* l3 = createList(arr3);

    // Store in vector
    vector<ListNode*> lists = {l1, l2, l3};

    // Merge lists
    Solution sol;
    ListNode* merged = sol.mergeKLists(lists);

    // Print result
    cout << "Merged Linked List: ";
    printList(merged);

    return 0;
}
