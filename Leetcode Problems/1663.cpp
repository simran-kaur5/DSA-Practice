#include <iostream>
#include <string>
#include <algorithm> // for min
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');  // Start with 'a's
        k -= n;              // Remaining value to distribute

        int i = n - 1;       // Start from the end
        while (k > 0) {
            int temp = min(k, 25);  // Max we can add to a letter
            res[i] += temp;
            k -= temp;
            i--;
        }

        return res;
    }
};

int main() {
    Solution sol;
    int n, k;

    cout << "Enter n (length of string): ";
    cin >> n;
    cout << "Enter k (numeric value sum): ";
    cin >> k;

    string result = sol.getSmallestString(n, k);
    cout << "Lexicographically smallest string: " << result << endl;

    return 0;
}
