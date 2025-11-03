#include<iostream>
#include<climits>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right=NULL;
    }
};

class Info{
    public:
    bool isBst;
    int sz,max,min;

    Info(bool isBst,int max,int min, int sz){
        this->isBst = isBst;
        this->sz = sz;
        this->max = max;
        this->min = min;
    }
};

static int maxSize =0;

Info* largest(Node* root){
    if(root==NULL){
        return new Info(true,INT_MIN,INT_MAX,0);
    }

    Info* leftInfo = largest(root->left);
    Info* rightInfo = largest(root->right);

    int currMin = min(root->data,min(leftInfo->min,rightInfo->min));
    int currMax = max(root->data,max(leftInfo->max,rightInfo->max));
    int currSz = leftInfo->sz + rightInfo -> sz +1;

    if(leftInfo->isBst && rightInfo->isBst && root->data > leftInfo->max && root->data < rightInfo->min){
        maxSize = currSz;
        return new Info(true,currMax,currMin,currSz);
    }
    return new Info(false,currMax,currMin,currSz);
}
int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right->left = new Node(8);
    root->right->right = new Node(12);

    largest(root);
    cout<<"Max Size of BST in BT: "<<maxSize<<endl;

    return 0;
}