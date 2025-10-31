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

void printInRange(Node* root,int st,int end){
    if(root==NULL){
        return;
    }
    if(st <= root->data && root->data <=end){
        cout<<root->data<<" ";

        printInRange(root->left,st,end);
        printInRange(root->right,st,end);

    }else if(st<=root->data){
        printInRange(root->left,st,end);
    }else if(root->data <= end){
        printInRange(root->right,st,end);
    }
}
int main(){
    int arr[]= {5,2,3,7,10,6};
    int n =6;
    Node* root = build(arr,n);
    cout<<endl;
    printInRange(root,5,12);
    return 0;
}