#include <bits/stdc++.h>
using namespace std;

bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    queue<int> q;
    vector<bool> visited(n, false);

    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int idx = q.front();
        q.pop();

        // If we reached a cell with value 0 → success
        if(arr[idx] == 0) return true;

        // Jump right
        int right = idx + arr[idx];
        if(right < n && !visited[right]) {
            visited[right] = true;
            q.push(right);
        }

        // Jump left
        int left = idx - arr[idx];
        if(left >= 0 && !visited[left]) {
            visited[left] = true;
            q.push(left);
        }
    }

    return false;
}

int main() {
    vector<int> arr = {4,2,3,0,3,1,2};
    int start = 5;

    bool result = canReach(arr, start);

    if(result) cout << "true\n";
    else cout << "false\n";

    return 0;
}
