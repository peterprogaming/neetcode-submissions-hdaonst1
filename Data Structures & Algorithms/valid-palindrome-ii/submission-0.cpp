class Solution {
public:
    bool validPalindrome(string s) {
        bool del = false, paldel = false;
        int l = 0, r = s.size() - 1;
        while (l <= r){
            if (s[l] != s[r]){
                del = true;
                break;
            }
            ++l; --r;
        }
        if (del){
            for (int k = 0; k < s.length(); ++k){
                l = 0, r = s.size() - 1;
                paldel = true;
                while (l <= r){
                    if (l == k){
                        ++l;
                        continue;
                    }
                    if (r == k){
                        --r; continue;
                    }
                    if (s[l] != s[r]){
                        paldel = false;
                        break;
                    }
                    ++l; --r;
                }
                if (paldel) return true;
            }
            return false;
        }
        else return true;
    }
};