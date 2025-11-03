#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left=right=NULL;
    }
};

Node* createBST(vector<int>&arr,int st,int end){
    if(end<st){
        return NULL;
    }

    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = createBST(arr,st,mid-1);
    curr->right = createBST(arr,mid+1,end);

    return curr;
}

void print(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int main(){

    vector<int>arr = {1,2,3,4,5,6,7};
    int n = arr.size();

    Node* root = createBST(arr,0,n-1);

    print(root);
    return 0;
}