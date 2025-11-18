#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Node
{
public:
    unordered_map<char, Node *> child;
    bool endOfWord;

    Node()
    {
        endOfWord = false;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(string str)
    {
        Node *temp = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (temp->child.count(str[i]) == 0)
            {
                temp->child[str[i]] = new Node();
            }
            temp = temp->child[str[i]];
        }

        temp->endOfWord = true;
    }

    bool search(string str)
    {
        Node *temp = root;

        for (int i = 0; i < str.length(); i++)
        {
            if (temp->child.count(str[i]) == 1)
            {
                temp = temp->child[str[i]];
            }
            else
            {
                return false;
            }
        }
        return temp->endOfWord;
    }

    bool startWith(string key)
    {
        Node *temp = root;
        for (int i = 0; i < key.length(); i++)
        {
            if (temp->child.count(key[i]) == 1)
            {
                temp = temp->child[key[i]];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

void build(vector<string> &str, string key)
{
    Trie trie;
    for (int i = 0; i < str.size(); i++)
    {
        trie.insert(str[i]);
    }

    if (trie.startWith(key))
    {
        cout << "Key is present" << endl;
    }
    else
    {
        cout << "key is not present" << endl;
    }
}
int main()
{

    vector<string> vec = {"apple", "app", "mango", "man", "woman"};

    build(vec, "app");

    return 0;
}