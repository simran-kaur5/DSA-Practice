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

bool isValid(Node* root,Node* max,Node* min){
    if(root == NULL){
        return true;
    }

    if(min!=NULL && root->data <= min->data){
        return false;
    }
    if(max!=NULL && root->data >= max->data){
        return false;
    }

    return isValid(root->left,root,min)
    && isValid(root->right,max,root);

}

int main(){
    int arr[]= {5,2,6,7,10,6};
    int n =6;
    Node* root = build(arr,n);

    if(isValid(root,NULL,NULL)){
        cout<<"BST is valid...";
    }else{
        cout<<"Not valid";
    }
    return 0;
}