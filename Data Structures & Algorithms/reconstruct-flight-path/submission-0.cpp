class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets){
        unordered_map<string, vector<string>> adj;
        
        for (const auto& i : tickets) adj[i[0]].push_back(i[1]);
        for (auto& [x, y] : adj) sort(y.rbegin(), y.rend());

        vector<string> res;
        stack<string> st;
        st.push("JFK");

        while (!st.empty()){
            string cur = st.top();

            if (adj[cur].empty()){
                res.push_back(cur);
                st.pop();
            }
            else {
                string nxt = adj[cur].back();
                adj[cur].pop_back();
                st.push(nxt);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};