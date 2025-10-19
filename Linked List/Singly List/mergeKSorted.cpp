
#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
ListNode* mergeS(ListNode* list1 , ListNode* list2){
    ListNode* i =list1;
    ListNode* j=list2;
    ListNode* merged = new ListNode(-1);
    ListNode* mtr = merged;
    while(i!=NULL && j!=NULL){
        if(i->val<j->val){
            mtr->next = i;
            mtr = mtr->next;
            i=i->next;
        }else{
            mtr->next = j;
             mtr = mtr->next;
            j=j->next;
        } 
    }
    if(i!=NULL){
        mtr->next = i;
    }
    else{
        mtr->next =j;
    }

    return merged->next;
}

ListNode* mergeSort(ListNode* list1 , ListNode* list2 , ListNode* list3){

    ListNode* newHead = mergeS(list1,list2);
    ListNode* result = mergeS(newHead,list3);

    return result;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Example usage
int main() {
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 3, 4};
    int arr3[] = {2, 6};

    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);
    ListNode* list3 = createList(arr3, 2);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    cout << "List 3: ";
    printList(list3);

    ListNode* newHead = mergeSort(list1,list2,list3);
    printList(newHead);
    return 0;
}


