class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> mp;
        int l = 0, res = 0;
        for (int r = 0; r < s.length(); ++r){
            while (mp.find(s[r]) != mp.end()){
                mp.erase(s[l]);
                ++l;
            }
            mp.insert(s[r]);
            res = max (res, r - l + 1);
        }
        return res;
    }
};
