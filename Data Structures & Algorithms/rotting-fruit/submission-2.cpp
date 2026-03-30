class Solution {
public:
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int res = 0, rotAll = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if (grid[i][j] == 1) ++rotAll;
        for (int i = 0; i < ROWS; ++i)
            for (int j = 0; j < COLS; ++j)
                if (grid[i][j] == 2) q.push({i, j});
        while (!q.empty() && rotAll > 0){
            int len = q.size();
            for (int i = 0; i < len; ++i){
                auto node = q.front();
                int r = node.first, c = node.second;
                q.pop();
                for (int i = 0; i < 4; ++i){
                    int dr = r + d[i][0], dc = c + d[i][1];
                    if (dr >= 0 && dc >= 0 && dr < grid.size() && dc < grid[0].size() && grid[dr][dc] == 1){
                        --rotAll;
                        grid[dr][dc] = 2;
                        q.push({dr, dc});
                    }
                }
            }
            ++res;
        }
        return (rotAll == 0) ? res : -1;
    } 
};
