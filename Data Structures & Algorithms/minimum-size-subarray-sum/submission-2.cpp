class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long add = 0, sum = 0; int res = INT_MAX, l = 0, r = 0;
        for (const auto& i : nums)
            add += i;
        if (add < target) return 0;
        else {
            for (r = 0; r < nums.size(); ++r){
                sum += nums[r];
                while (sum >= target){
                    res = min (res, r - l + 1);
                    sum -= nums[l];
                    ++l;
                }
            }
        }
        return res;
    }
};