class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points){
        int n = points.size(), node = 0, edges = 0, res = 0;
        vector<int> dist(n, 100000000);
        vector<bool> vis(n, false);

        while (edges < n - 1){
            vis[node] = true;
            int nextnode = -1;

            for (int i = 0; i < n; ++i){
                if (vis[i]) continue;

                int cur = abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1]);
                dist[i] = min(dist[i], cur);

                if (nextnode == -1 || dist[i] < dist[nextnode])
                    nextnode = i;
            }

            res += dist[nextnode];
            node = nextnode;
            ++edges;
        }
        return res;
    }
};