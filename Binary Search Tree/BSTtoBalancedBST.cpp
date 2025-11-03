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

void inOrder(Node*root,int arr[],vector<int>&vec){
    if(root==NULL){
        return;
    }

    inOrder(root->left,arr,vec);
    vec.push_back(root->data);
    inOrder(root->right,arr,vec);
}

Node* createBST(vector<int>&arr,int st,int end){
    if(st>end){
        return NULL;
    }

    int mid = st+ (end-st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = createBST(arr,st,mid-1);
    curr->right = createBST(arr,mid+1,end);

    return curr;
}
int main(){
    int arr[]= {5,2,3,8,7,10,6};
    int n =7;
    Node* root = build(arr,n);
    vector<int>vec;
    inOrder(root,arr,vec);
    
    Node* newRoot = createBST(vec,0,vec.size()-1);

    print(newRoot);
    return 0;
}