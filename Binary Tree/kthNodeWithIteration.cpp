#include<iostream>
#include<vector>
#include<queue>
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

void kthlevel(Node* root, int k){
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,1));

    while(!q.empty()){
        pair<Node*,int> curr = q.front();
        q.pop();
        Node* currNode = curr.first;
        int currLevel = curr.second;


        if(currLevel==k){
            cout<<currNode->data<<" ";
        }

        else if(currLevel > k){
            break; // stop early — no need to process further levels
        }
        if(currNode->left){
            q.push(make_pair(currNode->left,currLevel+1));
        }

        if(currNode->right){
            q.push(make_pair(currNode->right,currLevel+1));
        }
    }
}
int main(){

    vector<int>nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node * root = buildTree(nodes);

    kthlevel(root,3);
    return 0;
}