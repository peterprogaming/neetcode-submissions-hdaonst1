class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1, sum = 0;

        for (int i = n - 1; i >= 0; --i)
            if (i + nums[i] >= n) n = i;
        return n == 0;
    }
};
