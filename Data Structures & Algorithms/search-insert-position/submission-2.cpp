class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m;
        while (l <= r){
            m = (l + r) / 2;
            if (nums[m] == target) return m;
            if (nums[m] < target) l = m + 1;
            if (nums[m] > target) r = m - 1;
        }
        auto it = upper_bound (nums.begin(), nums.end(), target);
        if (it != nums.end()) return it - nums.begin();
        else return nums.size();
    }
};