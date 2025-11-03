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

void inOrder(Node* root,vector<int>&vec){
    if(root==NULL){
        return;
    }

    inOrder(root->left,vec);
    vec.push_back(root->data);
    inOrder(root->right,vec);

}

Node* mergedToBst(vector<int>&merged , int st,int end){
    if(st>end){
        return NULL;
    }

    int mid = st+(end-st)/2;
    Node* curr = new Node(merged[mid]);

    curr->left = mergedToBst(merged,st,mid-1);
    curr->right = mergedToBst(merged,mid+1,end);

    return curr;

}

Node* mergeBST(Node* root1,Node* root2){
    vector<int>vec1;
    vector<int>vec2;
    vector<int>merged;


    inOrder(root1,vec1);
    inOrder(root2,vec2);

    int i =0,j=0;

    while(i<vec1.size() && j<vec2.size()){
        if(vec1[i]>vec2[j]){
            merged.push_back(vec2[j]);
            j++;
        }else{
            merged.push_back(vec1[i]);
            i++;
        }
    }

    while(i<vec1.size()){
        merged.push_back(vec1[i++]);
    }

    while(j<vec2.size()){
        merged.push_back(vec2[j++]);
    }

    Node* newRoot = mergedToBst(merged,0,merged.size()-1);
    return newRoot;
}

void print(Node* root){
    if(root==NULL){
        return;
    }

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
int main(){
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);


    Node* root2 = new Node(5);
    root2 -> left = new Node(4);
    root2 ->right = new Node(6);

    Node* newRoot = mergeBST(root1,root2);

    cout<<"First BST: ";
    print(root1);
    cout<<endl;
    cout<<"Second BST: ";
    print(root2);
    cout<<endl;
    cout<<"Merged BST: ";
    print(newRoot);
    cout<<endl;

    return 0;
}