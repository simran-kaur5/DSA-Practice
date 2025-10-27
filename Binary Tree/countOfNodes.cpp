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

static int idx =-1; 
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

void preOrder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";

    preOrder(root->left);
    preOrder(root->right);
}

int countNodes(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftN = countNodes(root->left);
    int rightN = countNodes(root->right);

    int curr = leftN + rightN;

    return curr+1;
}
int main(){

    vector<int>nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    Node * root = buildTree(nodes);

    preOrder(root);
    cout<<endl;
    cout<<countNodes(root);
    return 0;
}