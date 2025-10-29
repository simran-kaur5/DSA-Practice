#include<iostream>
#include<vector>
using namespace std;
class Node{   //create individual nodes
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left=right=NULL;
    }

};

static int idx =-1; // we declared it as static because we want it incremented at each level of recursion
Node* buildTree(vector<int>&nodes){
    idx++; 
    if(nodes[idx]==-1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;

}

void kthNode(Node* root , int k){
    if(root==NULL){
        return;
    }

    if(k==1){
        cout<<root->data<<" ";
    }

    kthNode(root->left,k-1);
    kthNode(root->right,k-1);
}
int main(){

    vector<int>nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node * root = buildTree(nodes);

    kthNode(root,3);
    return 0;
}