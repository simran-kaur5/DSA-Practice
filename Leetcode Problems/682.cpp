
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int n = operations.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            if (operations[i] == "+") {
                if (s.size() >= 2) {
                    int x1 = s.top();
                    s.pop();

                    int x2 = s.top();
                    s.pop();

                    int newRec = x1 + x2;

                    s.push(x2);
                    s.push(x1);
                    s.push(newRec);

                    sum += newRec;
                }
            } 
            else if (operations[i] == "C") {
                if (!s.empty()) {
                    int x = s.top();
                    s.pop();
                    sum -= x;
                }
            } 
            else if (operations[i] == "D") {
                if (!s.empty()) {
                    int x = s.top();
                    int newScore = 2 * x;

                    s.push(newScore);
                    sum += newScore;
                }
            } 
            else {
                int num = stoi(operations[i]);
                s.push(num);
                sum += num;
            }
        }

        return sum;
    }
};

int main() {
    Solution obj;

    vector<string> operations = {
        "5", "2", "C", "D", "+"
    };

    int result = obj.calPoints(operations);

    cout << "Total score: " << result << endl;

    return 0;
}
