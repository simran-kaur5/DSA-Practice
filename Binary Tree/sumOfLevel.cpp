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

void sumoflevel(Node* root){

    queue<Node*>q;
    int sum =0;

    q.push(root);
    q.push(NULL);//to track next level
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr==NULL){
            cout<<sum<<endl;
            sum=0;
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }else{
            sum+=curr->data;
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }

}
int main(){

    vector<int>nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node * root = buildTree(nodes);

    sumoflevel(root);
    return 0;
}