#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
        string key;
        int val;
        Node* next;

        Node(string key,int val){
            this->key = key;
            this->val = val;
            next = NULL;
        }
};

class hashTable{
    int currSize;
    int totalSize;
    Node** arr;

    void rehash(){
        Node** oldtable = arr;
        int oldSize=totalSize;
        totalSize*=2;
        currSize=0;
        arr = new Node*[totalSize];
        for(int i =0;i<totalSize;i++){
            arr[i]=NULL;
        }

        //copy elemets to newtable

        for(int i =0;i<oldSize;i++){
            Node* temp = oldtable[i];

            while(temp!=NULL){
                insert(temp->key,temp->val);
                temp = temp->next;
            }
        }

        delete[] oldtable;
    }

    int hasFun(string key){
        int idx =0;
        for(int i =0;i<key.length();i++){   //O(1)
            idx = (idx + key[i] * key[i])%totalSize;
        }
        return idx%totalSize;
    }
    public:

    hashTable(int totalSize){
        this->totalSize = totalSize;
        currSize =0;
        arr = new Node*[totalSize];
        for(int i=0;i<totalSize;i++){
        arr[i] = NULL;
    }
    }

    void insert(string key,int val){ 
        int idx = hasFun(key);
        Node* newNode = new Node(key,val);
        newNode->next = arr[idx];
        arr[idx]=newNode;
        currSize++;

        double loadFactor = (1.0 * currSize) / totalSize;
if (loadFactor > 0.7) rehash();
        }


bool exists(string key){
    int idx = hasFun(key);
    Node* temp = arr[idx];

    while(temp!=NULL){
        if(temp->key==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
int search(string key){
    int idx = hasFun(key);
    Node* temp = arr[idx];

    while(temp!=NULL){
        if(temp->key==key){
            return temp->val;
        }
         temp = temp->next;
    }
    return -1;
}

void remove(string key){
    int idx =hasFun(key);

    Node* temp = arr[idx];
    Node* prev = temp;

    while(temp!=NULL){
        if(temp->key==key){
            if(temp==prev){
                arr[idx] = temp->next;
            }else{
                prev->next = temp->next;
            }
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

void print(){
    for(int i =0;i<totalSize;i++){
        Node* temp = arr[i];
        while(temp!=NULL){
            cout<<temp->key<<" -> "<<temp->val<<" ";
            temp = temp->next;
        }
    }
}
};
int main(){

    hashTable ht(6);
    ht.insert("India",123);
    ht.insert("US",129);
    ht.insert("china",33);
    ht.insert("UK",22);
    ht.insert("goa",10);

    ht.print();

    return 0;
}