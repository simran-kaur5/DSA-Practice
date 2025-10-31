#include<iostream>
#include<vector>
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

Node* insert(Node* root,int val){
    if(root==NULL){
        root = new Node(val);
        return root;
    }

    if(root->data>val){
        root->left = insert(root->left,val);
    }else{
        root -> right = insert(root->right,val);
    }

    return root;
}

Node* build(int arr[],int n){
    Node* root = NULL;

    for(int i =0;i<n;i++){
        root = insert(root,arr[i]);
    }
    return root;
}

void print(Node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

void printVec(vector<int>&ans){
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}
void rootToLeaf(Node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }

    ans.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        printVec(ans);
    }
    rootToLeaf(root->left,ans);
    rootToLeaf(root->right,ans);
    ans.pop_back();
}

int main(){
    int arr[]= {5,2,3,7,10,6};
    int n =6;
    Node* root = build(arr,n);
    vector<int>ans;
    rootToLeaf(root,ans);
    return 0;
}