class Solution {
public:
    bool hasDuplicate(vector <int>& nums) {
        map <int, long long> mp;
        for (int i = 0; i < nums.size(); ++i) ++mp[nums[i]];
        for (auto it : mp)
            if (it.second > 1) return true;
        return false;
    }
};