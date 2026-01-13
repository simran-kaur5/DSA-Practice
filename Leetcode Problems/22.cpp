#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void make(int open, int closed, int n, string ans, vector<string>& vec) {
        // base case
        if (ans.length() == 2 * n) {
            vec.push_back(ans);
            return;
        }

        // add '(' if possible
        if (open < n) {
            make(open + 1, closed, n, ans + '(', vec);
        }

        // add ')' if possible
        if (closed < open) {
            make(open, closed + 1, n, ans + ')', vec);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        make(0, 0, n, "", vec);
        return vec;
    }
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution sol;
    vector<string> result = sol.generateParenthesis(n);

    cout << "Valid Parentheses Combinations:\n";
    for (auto &s : result) {
        cout << s << endl;
    }

    return 0;
}
