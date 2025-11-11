#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to simulate stone smashing
int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;

    // Push all stones into a max-heap
    for (int stone : stones) {
        pq.push(stone);
    }

    // Keep smashing until ≤ 1 stone left
    while (pq.size() > 1) {
        int val1 = pq.top(); pq.pop();  // heaviest stone
        int val2 = pq.top(); pq.pop();  // 2nd heaviest

        // If they aren't equal, push the difference
        if (val1 != val2) {
            pq.push(abs(val1 - val2));
        }
    }

    // Return remaining stone or 0 if none left
    return pq.empty() ? 0 : pq.top();
}

int main() {
    // Example input
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    int result = lastStoneWeight(stones);

    cout << "Last stone weight: " << result << endl;

    return 0;
}
