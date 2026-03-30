class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;
        dp[1][1] = 1;

        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                if (i == 1 && j == 1) continue;
                if (grid[i - 1][j - 1] == 0) dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                else dp[i][j] = 0;
            }
        }
        return static_cast<int>(dp[m][n]);
    }
};