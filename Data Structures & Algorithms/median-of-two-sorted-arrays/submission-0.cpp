class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> nums; double res;
        for (const auto& i : nums1)
            nums.push_back(i);
        for (const auto& i : nums2)
            nums.push_back(i);
        sort (nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, m;
        if (nums.size() % 2 != 0){
            m = l + (r - l) / 2;
            return nums[m];
        }
        else {
            m = l + (r - l) / 2;
            res = (double) (nums[m] + nums[m + 1]) / 2;
            return res;
        }
    }
};
