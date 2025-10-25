#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.length() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main() {
    Solution sol;

    // Example test case
    string num = "35420";
    string result = sol.largestOddNumber(num);

    cout << "Input number: " << num << endl;
    cout << "Largest odd-number substring: " << result << endl;

    return 0;
}
