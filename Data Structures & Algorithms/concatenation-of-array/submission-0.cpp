class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector <int> res;
        int t = 2;
        while (t--){
            for (int i = 0; i < nums.size(); ++i)
                res.push_back(nums[i]);
        }
        return res;
    }
};