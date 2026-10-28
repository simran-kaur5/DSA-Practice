
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for (int i = 0; i < asteroids.size(); i++) {
            bool isSmall = false;

            if (asteroids[i] < 0) {
                while (!s.empty() && s.top() > 0) {
                    int num1 = -asteroids[i];
                    int num2 = s.top();

                    if (num1 < num2) {
                        isSmall = true;
                        break;
                    } 
                    else if (num1 == num2) {
                        s.pop();
                        isSmall = true;
                        break;
                    }

                    s.pop();
                }

                if (!isSmall) {
                    s.push(asteroids[i]);
                }
            } 
            else {
                s.push(asteroids[i]);
            }
        }

        vector<int> ans;

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> asteroids = {5, 10, -5};

    vector<int> result = sol.asteroidCollision(asteroids);

    cout << "Result: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
