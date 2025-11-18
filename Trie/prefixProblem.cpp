#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
public:
    unordered_map<char,Node*>child;
    bool endOfWord;
    int freq;

    Node(){
        endOfWord = false;
    }
};

class Trie{
    public:
    Node* root;

    Trie(){
        root=new Node();
        root->freq = -1;
    }

    void insert(string str){
        Node* temp = root;
        for(int i =0;i<str.length();i++){
            if(temp->child.count(str[i])==0){
                temp->child[str[i]] = new Node();
                temp->child[str[i]]->freq =1; 
            }else{
                temp->child[str[i]]->freq++; 
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
    
    string getPrefix(string str){
        Node* temp = root;
        string preFix = "";
        for(int i =0;i<str.length();i++){
            preFix+=str[i];

            if(temp->child[str[i]]->freq == 1){
                return preFix;
            }
            temp = temp->child[str[i]];
        }
        return preFix;
    }
};

void prefix(vector<string>&str){
    Trie trie;

    for(int i =0;i<str.size();i++){
        trie.insert(str[i]);
    }

    for(int i =0;i<str.size();i++){
        cout<<trie.getPrefix(str[i])<<" ";
    }

}
int main(){

    vector<string>vec = {"zebra","dog","duck","dove"};

    prefix(vec);
    return 0;
}