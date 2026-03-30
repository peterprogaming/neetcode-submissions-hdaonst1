class Solution {
public:
    vector <vector <int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector <int> cur; vector <bool> pick(nums.size(), false);
        backtrack(nums, cur, pick);
        return res;
    }
    void backtrack(vector <int>& nums, vector <int>& cur, vector <bool>& pick){
        if (cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); ++i){
            if (!pick[i]){
                cur.push_back(nums[i]);
                pick[i] = true;
                backtrack(nums, cur, pick);
                cur.pop_back();
                pick[i] = false;
            }
        }
    }
};
