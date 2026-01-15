#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct cmp {
    bool operator()(pair<int,string>& a, pair<int,string>& b) {
        if (a.first == b.first) {
            return a.second > b.second; // lexicographically larger = lower priority
        }
        return a.first > b.first; // smaller frequency = higher priority
    }
};

int main() {
    vector<string> words = {"love","i","leetcode","i","love","coding"};
    int k = 2;

    unordered_map<string,int> freq;
    for (string &w : words) {
        freq[w]++;
    }

    priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;

    for (auto &p : freq) {
        pq.push({p.second, p.first});
        if (pq.size() > k) {
            pq.pop();
        }
    }

    vector<string> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    
    
    for (string &s : result) {
        cout << s << " ";
    }

    return 0;
}
