#include<iostream>
#include<vector>
#include<map>
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

void topView(Node* root){
    queue<pair<Node*,int>>q;

    map<int,int>m;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node* , int>curr = q.front();
        q.pop();
        Node* currNode = curr.first;
        int currHd = curr.second;

        if(m.count(currHd)==0){
            m[currHd] = currNode->data;
        }

        if(currNode->left){
            q.push(make_pair(currNode->left,currHd-1));
        }
        if(currNode->right){
            q.push(make_pair(currNode->right,currHd+1));
        }
    }

    for(auto it:m){
        cout<<it.second<<" ";
    }
}
int main(){

    vector<int>nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node * root = buildTree(nodes);

    topView(root);

    return 0;
}