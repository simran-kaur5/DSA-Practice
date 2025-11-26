#include <iostream>
#include <vector>
using namespace std;

void dfs(int room, vector<bool>& visited, vector<vector<int>>& rooms) {
    visited[room] = true;
    for(int key : rooms[room]) {
        if(!visited[key]) {
            dfs(key, visited, rooms);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);

    dfs(0, visited, rooms);

    // Check if all rooms were visited
    for(bool v : visited) {
        if(!v) return false;
    }
    return true;
}

int main() {
    // You can change the test case here
    vector<vector<int>> rooms = {
        {1,3},
        {3,0,1},
        {2},
        {0}
    };

    if(canVisitAllRooms(rooms)) {
        cout << "All rooms can be visited!" << endl;
    } else {
        cout << "Not all rooms can be visited!" << endl;
    }

    return 0;
}
