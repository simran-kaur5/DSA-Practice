#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        int INF = amt + 1;   // safe infinity

        vector<vector<int>> dp(n + 1, vector<int>(amt + 1, INF));

        // Base case: amount 0 needs 0 coins
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            int coin = coins[i - 1];
            for (int j = 1; j <= amt; j++) {
                if (coin <= j) {
                    dp[i][j] = min(
                        dp[i - 1][j],        // don't take coin
                        1 + dp[i][j - coin]  // take coin (count +1)
                    );
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][amt] > amt ? -1 : dp[n][amt];
    }
};

int main() {
    Solution sol;

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << sol.coinChange(coins, amount) << endl; // Output: 3
    return 0;
}
