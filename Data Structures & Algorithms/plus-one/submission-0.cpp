class Solution {
public:
    vector<int> plusOne(vector<int>& digits){
        vector<int> res;
        int d = 1;

        for (int i = digits.size() - 1; i >= 0; --i){
            int sum = digits[i] + d;
            res.push_back(sum % 10);
            d = sum / 10;
        }

        if (d) res.push_back(d);
        reverse(res.begin(), res.end());
        return res;
    }
};
