class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        long long dp[203][203];
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < 203; ++i)
            for (int j = 0; j < 203; ++j)
                dp[i][j] = 0;

        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                if (i == 1)  dp[i][j] = grid[i - 1][j - 1] + dp[i][j - 1];
                if (j == 1) dp[i][j] = grid[i - 1][j - 1] + dp[i - 1][j];
                if (i != 1 && j != 1) dp[i][j] = grid[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};