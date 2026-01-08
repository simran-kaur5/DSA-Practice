#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Empty string matches empty pattern
        dp[0][0] = true;

        // If pattern is empty but string is not
        for (int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }

        // If string is empty but pattern has characters
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1]; // '*' can match an empty string
            } else {
                dp[0][j] = false;
            }
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};

int main() {
    Solution sol;

    string s, p;
    cout << "Enter string: ";
    cin >> s;

    cout << "Enter pattern: ";
    cin >> p;

    if (sol.isMatch(s, p))
        cout << "Match Found" << endl;
    else
        cout << "No Match" << endl;

    return 0;
}
