#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        if(!dict.count(endWord)) return 0;

        queue<pair<string,int>> q;  
        q.push({beginWord, 1});
        
        unordered_set<string> visited;
        visited.insert(beginWord);

        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            for(int i = 0; i < word.length(); i++) {
                string temp = word;

                for(char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if(temp == endWord) return steps + 1;

                    if(dict.count(temp) && !visited.count(temp)) {
                        visited.insert(temp);
                        q.push({temp, steps + 1});
                    }
                }
            }
        }

        return 0;
    }
};

int main() {

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    Solution obj;
    cout << obj.ladderLength(beginWord, endWord, wordList);

    return 0;
}
