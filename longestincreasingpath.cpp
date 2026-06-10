#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    const int diff[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

    int dfs(vector<vector<int>>& matrix,
            vector<vector<int>>& dp,
            int R, int C,
            int row, int col) {

        if(dp[row][col] != 0)
            return dp[row][col];

        int adjMax = 0;

        for(int i = 0; i < 4; i++) {
            int ar = row + diff[i][0];
            int ac = col + diff[i][1];

            if(ar >= 0 && ar < R &&
               ac >= 0 && ac < C &&
               matrix[ar][ac] > matrix[row][col]) {

                adjMax = max(adjMax,
                             dfs(matrix, dp, R, C, ar, ac));
            }
        }

        dp[row][col] = 1 + adjMax;
        return dp[row][col];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return 0;

        int R = matrix.size();
        int C = matrix[0].size();

        vector<vector<int>> dp(R, vector<int>(C, 0));

        int ans = 0;

        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                ans = max(ans, dfs(matrix, dp, R, C, i, j));
            }
        }

        return ans;
    }
};

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> matrix(R, vector<int>(C));

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    cout << obj.longestIncreasingPath(matrix);

    return 0;
}