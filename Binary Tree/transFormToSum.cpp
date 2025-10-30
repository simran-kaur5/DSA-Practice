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

int transform(Node* root){   //O(n)
    if(root==NULL){
        return 0;
    }

    int leftSum = transform(root->left);
    int rightSum = transform(root->right);
    int currVal = root->data;

    root->data = leftSum + rightSum;

    return root->data + currVal;
}
int main(){

    vector<int>nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node * root = buildTree(nodes);

    cout<<transform(root);

    
    return 0;
}