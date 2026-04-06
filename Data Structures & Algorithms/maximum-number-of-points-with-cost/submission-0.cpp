class Solution {
public:
    long long maxPoints(vector<vector<int>>& points){
        int rows = points.size(), cols = points[0].size();
        vector<long long> prev(cols);
        
        for (int c = 0; c < cols; ++c) prev[c] = points[0][c];

        for (int r = 1; r < rows; ++r){
            vector<long long> cur(cols);
            long long rmax = prev[cols - 1];
            cur[0] = prev[0];

            for (int c = 1; c < cols; ++c) cur[c] = max(prev[c], cur[c - 1] - 1);

            for (int c = cols - 2; c >= 0; --c){
                rmax = max(prev[c], rmax - 1);
                cur[c] = max(cur[c], rmax) + points[r][c];
            }

            cur[cols - 1] += points[r][cols - 1];
            prev = cur;
        }
        return *max_element(prev.begin(), prev.end());
    }
};