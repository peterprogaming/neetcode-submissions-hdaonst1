class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> adj(numCourses);
        for (const auto& p : prerequisites){
            int a = p[0], b = p[1];
            adj[b].push_back(a);
        }
        
        vector<int> color(numCourses, 0);

        for (int i = 0; i < numCourses; ++i)
            if (color[i] == 0) 
                if (dfs(i, adj, color)) return false;
        return true;
    }
private:
    bool dfs(int v, const vector<vector<int>>& adj, vector<int>& color) {
        color[v] = 1;
        
        for (int nei : adj[v]){
            if (color[nei] == 0){
                if (dfs(nei, adj, color)) return true;
            }
            else if (color[nei] == 1) return true;
        }

        color[v] = 2;
        return false;
    }
};