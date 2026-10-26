
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) {
                     return a[1] < b[1];
                 }
                 return a[0] > b[0];
             });

        vector<vector<int>> queue;

        for (int i = 0; i < people.size(); i++) {
            int k = people[i][1];
            queue.insert(queue.begin() + k, people[i]);
        }

        return queue;
    }
};

int main() {
    vector<vector<int>> people = {
        {6, 0},
        {5, 2},
        {4, 0},
        {6, 1},
        {5, 0}
    };

    Solution sol;
    vector<vector<int>> result = sol.reconstructQueue(people);

    cout << "[ ";
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]";
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << " ]" << endl;

    return 0;
}
