class Solution {
public:
    vector<int> productExceptSelf(vector <int>& nums) {
        int product = 1;
        vector <int> res;
        for (int i = 0; i < nums.size(); ++i){
            product = 1;
            for (int j = 0; j < nums.size(); ++j)
                if (i != j) product *= nums[j];
            res.push_back (product);
        }
        return res;
    }
};
