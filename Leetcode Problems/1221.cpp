#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int r = 0, l = 0;
        int bal = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') {
                r++;
            } else {
                l++;
            }

            if (r == l) {
                bal++;
            }
        }
        return bal;
    }
};

int main() {
    Solution sol;

    // Example test
    string s = "RLRRLLRLRL";
    int result = sol.balancedStringSplit(s);

    cout << "Input: " << s << endl;
    cout << "Maximum number of balanced substrings: " << result << endl;

    return 0;
}
