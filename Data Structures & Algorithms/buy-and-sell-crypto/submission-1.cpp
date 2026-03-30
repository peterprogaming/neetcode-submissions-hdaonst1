class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, min_val = prices[0];
        for (const auto& i : prices){
            profit = max (profit, i - min_val);
            min_val = min (min_val, i);
        }
        return profit;
    }
};
