class Solution {
    vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));
        queue<pair<int, int>> pacqueue, atlqueue;

        for (int c = 0; c < cols; ++c) {
            pacqueue.push({0, c});
            atlqueue.push({rows - 1, c});
        }
        for (int r = 0; r < rows; ++r) {
            pacqueue.push({r, 0});
            atlqueue.push({r, cols - 1});
        }

        bfs(pacqueue, pac, heights);
        bfs(atlqueue, atl, heights);

        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (pac[r][c] && atl[r][c])
                    res.push_back({r, c});
        return res;
    }
private:
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            ocean[r][c] = true;
            for (auto [dr, dc] : d) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c])
                    q.push({nr, nc});
            }
        }
    }
};