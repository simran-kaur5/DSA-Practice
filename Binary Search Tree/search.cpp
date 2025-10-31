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

bool search(Node* root,int key){
    if(root==NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(root->data > key){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}
int main(){
    int arr[]= {5,2,3,7,10,6};
    int n =6;
    Node* root = build(arr,n);
    if(search(root,10)){
        cout<<"Key is present in tree."<<endl;
    }else{
        cout<<"key is absent in tree."<<endl;
    }
    return 0;
}