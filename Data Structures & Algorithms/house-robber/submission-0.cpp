class Solution {
public:
    int rob(vector <int>& nums) {
        long long dp[105];
        for (int i = 0; i < 105; ++i) dp[i] = 0;
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        return dp[nums.size() - 1];
    }
};
