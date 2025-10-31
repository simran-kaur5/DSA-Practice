#include<iostream>
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

Node* inorderSucc(Node* root){

    while(root->left!=NULL){
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node* root,int val){
    if(root==NULL){
        return NULL;
    }

    if(root->data > val){
        root->left = deleteNode(root->left,val);
    }else if(root->data < val){
        root->right = deleteNode(root->right,val);
    }else{
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }

        if(root->left==NULL || root->right ==NULL){
           return root->left==NULL ? root->right:root->left; 
        }

        Node* IS = inorderSucc(root->right);
        root->data = IS->data;
        root->right = deleteNode(root->right,IS->data);
    }
    return root;
}
int main(){
    int arr[]= {5,2,3,7,10,6};
    int n =6;
    Node* root = build(arr,n);
    print(root);
    cout<<endl;
    deleteNode(root,5);
    print(root);
    
    return 0;
}