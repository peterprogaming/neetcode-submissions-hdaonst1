class Solution {
public:
    vector <vector <int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector <int> cur;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, cur, 0);
        return res;
    }
    void backtrack (vector <int>& candidates, int target, vector <int>& cur, int i){
        if (target == 0){
            res.push_back(cur);
            return;
        }
        if (i >= candidates.size() || target < 0) return;
        cur.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], cur, i + 1);
        cur.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) ++i;
        backtrack(candidates, target, cur, i + 1);
    }
};