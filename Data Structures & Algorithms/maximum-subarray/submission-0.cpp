class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()], res;

        for (int i = 0; i < nums.size(); ++i) dp[i] = 0;
        dp[0] = nums[0]; res = nums[0];

        for (int i = 1; i < nums.size(); ++i){
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};
