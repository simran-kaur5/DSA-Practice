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

Node* lca(Node* root,Node* p , Node* q){
    if(root==NULL){
        return NULL;
    }

    if(root==p || root==q){
        return root;
    }

    Node* leftHalf = lca(root->left,p,q);
    Node* rightHalf = lca(root->right,p,q);

    if(leftHalf && rightHalf){
        return root;
    }

    return leftHalf==NULL?rightHalf:leftHalf;
}

int distance(Node* root,Node* n){
    if(root==NULL){
        return -1;
    }

    if(root==n){
        return 0;
    }

    int leftSide = distance(root->left,n);
    if(leftSide!=-1){
        return leftSide+1;
    }
    int rightSide = distance(root->right,n);

    if(rightSide!=-1){
        return rightSide+1;
    }

    return -1;
}
int minDis(Node* root,Node* p,Node*q){
    if(root==NULL){
        return -1;
    }

    Node* l = lca(root,p,q);

    int distance1 = distance(l,p);
    int distance2 = distance(l,q);

    return distance1+distance2;
}
int main(){

    vector<int>nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node * root = buildTree(nodes);

    cout<<"min distance: "<<minDis(root,root->left->left,root->left->right);

    
    return 0;
}