class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        else {
            int l = 0, r = s1.size() - 1;
            map <char, int> mp; bool check = false;
            map <char, int> s1mp;
            for (const auto& i : s1) ++s1mp[i];
            while (r < s2.size()){
                check = true;
                for (auto& i : mp) i.second = 0;
                for (int i = l; i <= r; ++i) ++mp[s2[i]];
                for (const auto& i : s1){
                    if (mp[i] != s1mp[i]){
                        check = false;
                        break;
                    }
                }
                if (check) return true;
                ++l; ++r;
            }
            return false;
        }
    }
};
