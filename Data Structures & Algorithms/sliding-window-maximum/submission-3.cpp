class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = 0;
        vector <int> res; int max_val = nums[0];
        if (k == 1) return nums;
        while (r < nums.size()){
            while (r - l + 1 < k){
                if (nums[r] >= max_val) max_val = nums[r];
                ++r;
                if (nums[r] >= max_val) max_val = nums[r];
            }
            res.push_back(max_val);
            ++l; max_val = nums[l];
            if (r >= nums.size() - 1) break;
            r = l;
        }
        return res;
    }
};
