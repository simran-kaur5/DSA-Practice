#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& image, int sr, int sc, int color, int n, int m, int oldCol, vector<vector<bool>>& vis){

        vis[sr][sc] = true;
        image[sr][sc] = color;

        // left
        if(sc - 1 >= 0 && !vis[sr][sc - 1] && image[sr][sc - 1] == oldCol)
            helper(image, sr, sc - 1, color, n, m, oldCol, vis);

        // right
        if(sc + 1 < m && !vis[sr][sc + 1] && image[sr][sc + 1] == oldCol)
            helper(image, sr, sc + 1, color, n, m, oldCol, vis);

        // up
        if(sr - 1 >= 0 && !vis[sr - 1][sc] && image[sr - 1][sc] == oldCol)
            helper(image, sr - 1, sc, color, n, m, oldCol, vis);

        // down
        if(sr + 1 < n && !vis[sr + 1][sc] && image[sr + 1][sc] == oldCol)
            helper(image, sr + 1, sc, color, n, m, oldCol, vis);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        if(image[sr][sc] == color) return image;  // 🔥 important fix

        helper(image, sr, sc, color, n, m, image[sr][sc], vis);
        return image;
    }
};

int main() {
    Solution s;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;

    vector<vector<int>> result = s.floodFill(image, sr, sc, color);

    cout << "Output:\n";
    for(auto &row : result){
        for(int x : row) cout << x << " ";
        cout << "\n";
    }
}
