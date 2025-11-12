#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;

        for (char ch : s) {
            m[ch]++;
        }

        // Max heap: (frequency, character)
        priority_queue<pair<int,char>> pq;

        for (auto it = m.begin(); it != m.end(); it++) {
            pq.push({it->second, it->first});
        }

        pair<int,char> prev = {0, '#'};
        string res = "";

        while (!pq.empty()) {
            pair<int,char> curr = pq.top();
            pq.pop();

            res += curr.second;
            curr.first--;

            if (prev.first > 0) {
                pq.push(prev);
            }

            prev = curr;
        }

        return res.length() == s.length() ? res : "";
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    string result = sol.reorganizeString(s);

    if (result == "")
        cout << "Not possible to reorganize the string." << endl;
    else
        cout << "Reorganized string: " << result << endl;

    return 0;
}
