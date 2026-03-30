class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<bool> vis(n, false);
        int res = 0;

        for (const auto& i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        for (int i = 0; i < n; ++i){
            if (!vis[i]){
                ++res;
                bfs(i, vis, adj);
            }
        }
        return res;
    }
    void bfs(int u, vector<bool>& vis, vector<int> adj[]){
        queue<int> q;
        vis[u] = true;
        q.push(u);

        while (!q.empty()){
            int v = q.front();
            q.pop();
            for (int x : adj[v]){
                if (!vis[x]){
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
    }
};
