class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> st;

        for (int i = 0; i < temperatures.size(); ++i){
            int t = temperatures[i];
            
            while (!st.empty() && t > st.top().first){
                auto x = st.top();
                st.pop();
                res[x.second] = i - x.second;
            }
            st.push({t, i});
        }
        return res;
    }
};