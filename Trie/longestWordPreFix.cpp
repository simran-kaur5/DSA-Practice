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

    string longestString(Node *root, string &ans, string temp)
    {
        for (pair<char, Node *> p : root->child)
        {
            if (p.second->endOfWord)
            {
                temp += p.first;

                if ((temp.size() == ans.size() && temp < ans) || temp.size() > ans.size())
                {
                    ans = temp;
                }

                longestString(p.second, ans, temp);
                temp = temp.substr(0, temp.size() - 1);
            }
        }

        return ans;
    }
    void longest()
    {
        string ans = "";
        string temp = "";
        cout << longestString(root, ans, temp);
    }
};
int main()
{

    vector<string> vec = {"a", "banana", "app", "appl", "apple", "apply", "ap"};
    Trie trie;

    for (string str : vec)
    {
        trie.insert(str);
    }
    trie.longest();
    return 0;
}