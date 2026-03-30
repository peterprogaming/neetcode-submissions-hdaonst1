class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, max_val = 0, res = 0, r = 0;
        map <char, int> mp;
        for (r = 0; r < s.length(); ++r){
            ++mp[s[r]];
            for (const auto& i : mp) max_val = max (max_val, i.second);
            while ((r - l + 1) - max_val > k){
                --mp[s[l]];
                for (const auto& i : mp) max_val = max (0, i.second);
                for (const auto& i : mp) max_val = max (max_val, i.second);
                ++l;
            }
            res = max (res, r - l + 1);
        }
        return res;
    }
};