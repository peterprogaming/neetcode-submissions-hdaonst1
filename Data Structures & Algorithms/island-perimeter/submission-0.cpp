class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector <vector <bool>> visited(rows, vector <bool>(cols, false));
        int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (grid[r][c] == 1)
                    return bfs(grid, visited, r, c, d);
        return 0;
    }
    int bfs(vector <vector <int>>& grid, vector <vector <bool>>& visited, int r, int c, int d[4][2]){
        int perimeter = 0;
        queue <pair <int, int>> q;
        q.push({r, c});
        visited[r][c] = true;
        while (!q.empty()){
            pair <int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i){
                int nr = curr.first + d[i][0];
                int nc = curr.second + d[i][1];
                if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size())
                    ++perimeter;
                else if (grid[nr][nc] == 0) ++perimeter;
                else if (!visited[nr][nc]){
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return perimeter;
    }
};