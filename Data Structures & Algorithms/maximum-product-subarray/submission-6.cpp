class Solution {
public:
    int maxProduct(vector<int>& nums){
        int res = INT_MIN, curmax = 1, curmin = 1, tmp;
        int dp[1005]; dp[0] = nums[0];
        for (int i = 0; i < nums.size(); ++i){
            tmp = curmax * nums[i];
            curmax = max({nums[i], nums[i] * curmax, nums[i] * curmin});
            curmin = min({nums[i], tmp, nums[i] * curmin});
            res = max(res, curmax);
        }
        return res;
    }
};
