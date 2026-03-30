class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size(), dp1_mua = 0, dp1_sell = 0, dp2_mua = 0;

        for (int i = n - 1; i >= 0; --i){
            int dp_mua = max(dp1_sell - prices[i], dp1_mua);
            int dp_sell = max(dp2_mua + prices[i], dp1_sell);
            dp2_mua = dp1_mua;
            dp1_mua = dp_mua;
            dp1_sell = dp_sell;
        }

        return dp1_mua;
    }
};