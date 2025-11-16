#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> m;
        int bulls = 0, cows = 0;

        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]) bulls++;
            else m[secret[i]]++;
        }

        for(int i = 0; i < guess.size(); i++){
            if(secret[i] == guess[i]) continue;
            if(m[guess[i]] > 0){
                cows++;
                m[guess[i]]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main(){
    Solution sol;
    string secret = "1807", guess = "7810";
    cout << sol.getHint(secret, guess) << endl; // Output: 1A3B
    return 0;
}
