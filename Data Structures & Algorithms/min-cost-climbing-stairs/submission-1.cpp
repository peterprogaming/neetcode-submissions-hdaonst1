class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector <int> dp(102, 0);
        dp[0] = cost[0]; dp[1] = cost[1];
        for (int i = 2; i <= cost.size(); ++i){
            if (i < cost.size()) dp[i] = min(dp[i - 2] + cost[i], dp[i - 1] + cost[i]);
            else dp[i] = min(dp[i - 2], dp[i - 1]);
        }
        return dp[cost.size()];
    }
};
