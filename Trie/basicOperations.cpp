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
};
int main(){

    vector<string>vec = {"the","a","there","their","any","thee"};
    Trie trie;
    
    for(string str:vec){
        trie.insert(str);
    }
    cout<<trie.search("ther");
    return 0;
}