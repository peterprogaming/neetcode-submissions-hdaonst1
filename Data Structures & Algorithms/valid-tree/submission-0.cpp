class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        
        vector<int> adj[n];
        vector<bool> vis(n, false);
        vector<int> parent(n, -1);

        for (const auto& i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        if (!bfs(0, vis, parent, adj)) return false;

        for (bool v : vis)
            if (!v) return false;
        return true;
    }
    bool bfs(int u, vector<bool>& vis, vector<int>& parent, vector<int> adj[]){
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
                    parent[x] = v;
                }
                else if (x != parent[v]) return false;
            }
        }
        return true;
    }
};