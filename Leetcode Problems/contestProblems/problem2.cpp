#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while (num1 > 0 && num2 > 0) {
            if (num1 >= num2)
                num1 -= num2;
            else
                num2 -= num1;
            ans++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.countOperations(5, 2) << endl;   // Expected 4
    cout << sol.countOperations(10, 10) << endl; // Expected 1
    cout << sol.countOperations(7, 5) << endl;   // Expected 5
    return 0;
}
