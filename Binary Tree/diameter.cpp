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


pair<int,int >diameter(Node* root){
    if(root==NULL){
        return make_pair(0,0);
    }

    pair<int,int> leftInfo = diameter(root->left);
    pair<int,int> rightInfo = diameter(root->right);

    int currDia = leftInfo.second + rightInfo.second + 1;
    int maxDia=  max(currDia,max(leftInfo.first,rightInfo.first));
    int height = max(leftInfo.second,rightInfo.second)+1;
    return make_pair(maxDia,height);


}
int main(){

    vector<int> nodes = {
    1,
    2,
    4,
    5,
    7, -1, -1,  // left subtree of 5
    -1,          // right of 5
    6, -1, -1,   // right subtree of 4
    -1,          // right of 2
    3, -1, -1    // right subtree of 1
};


    Node * root = buildTree(nodes);

    cout<<diameter(root).first;   //first is diameter and second pair is height
    
    return 0;
}