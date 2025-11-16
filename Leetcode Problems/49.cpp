#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto &str: strs){
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            m[sortedStr].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto &p: m)
            ans.push_back(p.second);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = sol.groupAnagrams(strs);
    for(auto &v: ans){
        for(auto &s: v) cout << s << " ";
        cout << endl;
    }
    return 0;
}
