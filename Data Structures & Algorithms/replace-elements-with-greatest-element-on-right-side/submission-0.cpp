class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector <int> res;
        int maxright[n];
        maxright[n - 1] = -1;
        for (int i = n - 2; i >= 0; --i)
            maxright[i] = max(maxright[i + 1], arr[i + 1]);
        for (auto& i : maxright)
            res.push_back(i);
        return res;
    }
};