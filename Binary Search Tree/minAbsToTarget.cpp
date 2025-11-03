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
        left = right = NULL;
    }
};

static Node* ans = NULL;
static int val =INT_MAX;
void minAbs(Node* root,int target){
    if(root==NULL){
        return ;
    }

    if(val>abs(target-(root->data))){
        val = abs(target - root->data);
        ans = root;
    }

    if(target <= root->data){
        minAbs(root->left,target);
    }else{
        minAbs(root->right,target);
    }
    
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(11);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->right = new Node(20);

    minAbs(root,19);
    cout<<ans->data<<" ";

    return 0;
}