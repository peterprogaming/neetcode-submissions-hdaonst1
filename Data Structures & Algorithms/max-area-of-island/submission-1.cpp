class Solution {
public:
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int cur = 0, res = 0;
    bool islandExist = false;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        for (int r = 0; r < rows; ++r){
            for (int c = 0; c < cols; ++c){
                if (grid[r][c] == 1){
                    cur = 0;
                    islandExist = true;
                    bfs(grid, r, c);
                    res = max(res, cur);
                }
            }
        }
        if (!islandExist) return 0;
        return res + 1;
    }
    void bfs(vector <vector <int>>& grid, int r, int c){
        queue <pair <int, int>> q;
        grid[r][c] = 0;
        q.push({r, c});
        while (!q.empty()){
            auto v = q.front();
            int row = v.first; int col = v.second;
            q.pop();
            for (int i = 0; i < 4; ++i){
                int nr = row + d[i][0];
                int nc = col + d[i][1];
                if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                    ++cur;
                }
            }
        }
    }
};
