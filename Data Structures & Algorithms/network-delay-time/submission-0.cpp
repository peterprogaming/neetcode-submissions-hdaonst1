class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto& i : times) adj[i[0]].push_back({i[1], i[2]});
        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d > dist[u]) continue;

            for (auto& edge : adj[u]){
                int v = edge.first;
                int w = edge.second;

                if (dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int res = *max_element(dist.begin() + 1, dist.end());
        return (res == INT_MAX) ? -1 : res;
    }
};
