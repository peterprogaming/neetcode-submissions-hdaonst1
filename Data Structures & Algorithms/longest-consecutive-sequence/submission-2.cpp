class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort (nums.begin(), nums.end());
        int res = 1, cur = 0, mark = 0;
        for (int i = 0; i < nums.size() - 1; ++i){
            if ((nums[i + 1] == nums[i] + 1) && nums[i] - mark > 1)
                cur = 0;
            if (nums[i + 1] == nums[i] + 1){
                ++cur; mark = nums[i + 1];
            }
            res = max (res, cur + 1);
        }
        return res;
    }
};
