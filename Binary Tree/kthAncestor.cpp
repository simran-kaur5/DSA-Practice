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

int kthAnces(Node*root,int node,int k){
    if(root==NULL){
        return -1;
    }

    if(root->data==node){
        return 0;
    }

    int leftDis = kthAnces(root->left,node,k);
    int rightDis= kthAnces(root->right,node,k);

    if(leftDis==-1 && rightDis==-1){
        return -1;
    }

    int validVal = leftDis==-1?rightDis :leftDis;

    if(validVal+1 == k){
        cout<<"Value of kth ancestor is: "<<root->data<<" "<<endl;
    }
    
    return validVal+1;


}
int main(){

    vector<int>nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node * root = buildTree(nodes);

    kthAnces(root,4,2);

    return 0;
}