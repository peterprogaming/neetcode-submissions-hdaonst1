class Solution {
public:
    vector <vector <int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector <int> cur;
        vector <int> nums;
        for (int i = 1; i <= n; ++i) nums.push_back(i);
        if (k == n){
            res.push_back(nums);
            return res;
        }
        else {
            backtrack(res, cur, nums, n, k, 0);
            return res;
        }
    }
    void backtrack(vector <vector <int>>& res, vector <int>& cur, vector <int>& nums, int n, int k, int i){
        if (cur.size() == k){
            res.push_back(cur);
            return;
        }
        if (i >= nums.size()) return;
        cur.push_back(nums[i]);
        backtrack(res, cur, nums, n, k, i + 1);
        cur.pop_back();
        backtrack(res, cur, nums, n, k, i + 1);
    }
};