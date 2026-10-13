#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> s;

    StockSpanner() {
    }

    int next(int price) {
        if (s.empty()) {
            s.push({price, 1});
            return 1;
        } else {
            int ans = 0;

            while (!s.empty()) {
                auto [p, num] = s.top();

                if (p <= price) {
                    ans += num;
                    s.pop();
                } else {
                    break;
                }
            }

            s.push({price, ans + 1});
            return ans + 1;
        }
    }
};

int main() {
    StockSpanner* obj = new StockSpanner();

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    for (int price : prices) {
        cout << obj->next(price) << " ";
    }

    cout << endl;

    delete obj;
    return 0;
}