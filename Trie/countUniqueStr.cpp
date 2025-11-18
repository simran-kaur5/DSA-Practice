#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
public:
    unordered_map<char,Node*>child;
    bool endOfWord;

    Node(){
        endOfWord = false;
    }
};

class Trie{
    public:
    Node* root;

    Trie(){
        root=new Node();
    }

    void insert(string str){
        Node* temp = root;
        for(int i =0;i<str.length();i++){
            if(temp->child.count(str[i])==0){
                temp->child[str[i]] = new Node();
            }
            temp = temp->child[str[i]];
        }

        temp->endOfWord = true;
    }

    bool search(string str){
        Node* temp=root;

        for(int i =0;i<str.length();i++){
            if(temp->child.count(str[i])==1){
                temp = temp->child[str[i]];
            }else{
                return false;
            }
        }
        return temp->endOfWord;
    }

    int countUnique(string key,Node* root){
        int count =0;
        for(pair<char,Node*>p:root->child){
            count+=(countUnique(key,p.second));

        }
        return count+1;
    }
    int count(string key){
        return countUnique(key,root);
    }
};


int main(){

    string key ="apple";

    Trie trie;
    for(int i =0;i<key.length();i++){
        string suffix = key.substr(i);
        trie.insert(suffix);
    }

    cout<<"Count of unique substrings are: "<<trie.count(key);
    return 0;
}