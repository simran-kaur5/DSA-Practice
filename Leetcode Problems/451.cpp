#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c: s) freq[c]++;

        auto cmp = [&](char a, char b){
            if(freq[a] == freq[b]) return a > b;
            return freq[a] < freq[b];
        };

        sort(s.begin(), s.end(), cmp);
        return s;
    }
};

int main(){
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl; // Output: eetr or eert
    return 0;
}
