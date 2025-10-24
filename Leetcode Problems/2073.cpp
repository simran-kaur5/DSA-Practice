#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int n = tickets.size();

        // Push all indices into the queue
        for(int i = 0; i < n; i++) {
            q.push(i);
        }

        int time = 0;

        // Simulate ticket buying
        while(!q.empty() && tickets[k] != 0) {
            int idx = q.front();
            q.pop();

            tickets[idx]--;       // person buys 1 ticket
            time++;               // 1 second per ticket

            if(tickets[idx] > 0)  // if tickets remain, go to the end
                q.push(idx);
        }

        return time;
    }
};

int main() {
    // Sample input
    vector<int> tickets = {2, 3, 2};
    int k = 2;

    Solution sol;
    int result = sol.timeRequiredToBuy(tickets, k);

    cout << "Time required for person " << k << " to buy all tickets: " << result << endl;

    return 0;
}
