class Solution {
public:
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue <pair <int, int>> q;
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (grid[i][j] == 0) q.push({i, j});
        while (!q.empty()){
            auto node = q.front();
            int row = node.first, col = node.second;
            q.pop();
            for (int i = 0; i < 4; ++i){
                int r = row + d[i][0];
                int c = col + d[i][1];
                if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] != INT_MAX) continue;
                grid[r][c] = grid[row][col] + 1;
                q.push({r, c});
            }
        }
    }
};
