class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        map <char, int> mpt; string res = "";
        for (const auto& i : t) ++mpt[i];
        map <char, int> mp; bool check = false;
        int window = s.size(), len = INT_MAX;
        while (window >= t.size()){
            int l = 0, r = window - 1;
            while (r < s.size()){
                check = true;
                mp.clear();
                for (int i = l; i <= r; ++i)
                    ++mp[s[i]];
                for (auto const& [key, val] : mpt){
                    if (mp[key] < val){
                        check = false;
                        break;
                    }
                }
                if (check){
                    res = "";
                    for (int i = l; i <= r; ++i)
                        res = res + s[i];
                    len = window;
                    break;
                }
                ++l; ++r;
            }
            if (check) --window;
            else break;
        }
        return res;
    }
};