class Solution {
    vector<int> out;
    vector<int> ind;
    vector<vector<int>> adj;

    void dfs(int u){
        out.push_back(u);
        --ind[u];
        for (int v : adj[u]){
            --ind[v];
            if (ind[v] == 0) dfs(v);
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>> (numCourses);
        ind = vector<int> (numCourses, 0);
        for (auto& i : prerequisites){
            ++ind[i[0]];
            adj[i[1]].push_back(i[0]);
        }

        for (int i = 0; i < numCourses; ++i)
            if (ind[i] == 0) dfs(i);

        if (out.size() != numCourses) return {};
        return out;
    }
};
