#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list (same as LeetCode)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class (exactly what you'd submit to LeetCode)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        ListNode* temp = head;

        // Copy linked list values to vector
        while (temp != nullptr) {
            vec.push_back(temp->val);
            temp = temp->next;
        }

        // Two-pointer palindrome check
        int st = 0, end = vec.size() - 1;
        while (end >= st) {
            if (vec[st] != vec[end]) {
                return false;
            }
            st++;
            end--;
        }

        return true;
    }
};

// Helper: Create linked list from vector
ListNode* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper: Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function for testing locally
int main() {
    // Example 1: Palindrome list
    vector<int> nodes = {1, 2, 3, 2, 1};
    ListNode* head = createList(nodes);

    cout << "Linked List: ";
    printList(head);

    Solution sol;
    bool result = sol.isPalindrome(head);

    if (result)
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;

    return 0;
}
