#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startIdx = 0;
        int currGas = 0;

        int totalCost = 0;
        int totalGas = 0;
        int n = gas.size();

        for (int i = 0; i < n; i++) {
            totalCost += cost[i];
            totalGas += gas[i];
        }

        if (totalCost > totalGas) {
            return -1;
        }

        for (int i = 0; i < n; i++) {
            currGas += gas[i] - cost[i];

            if (currGas < 0) {
                currGas = 0;
                startIdx = i + 1;
            }
        }

        return startIdx;
    }
};

int main() {
    Solution sol;

    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    cout << sol.canCompleteCircuit(gas, cost) << endl;

    return 0;
}