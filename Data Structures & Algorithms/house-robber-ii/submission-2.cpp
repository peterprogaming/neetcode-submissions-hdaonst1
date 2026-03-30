class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int dp1[105], dp2[105], res = INT_MIN;
        for (int i = 0; i < 105; ++i) dp1[i] = dp2[i] = 0;
        dp1[0] = nums[0]; dp2[1] = nums[1];
        for (int i = 1; i < nums.size() - 1; ++i){
            if (i < 2){
                dp1[i] = max(nums[i], dp1[i - 1]); continue;
            }
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }
        for (int i = 1; i < nums.size(); ++i)
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        for (int i = 0; i < nums.size(); ++i)
            res = max({res, dp1[i], dp2[i]});
        return res;
    }
};
