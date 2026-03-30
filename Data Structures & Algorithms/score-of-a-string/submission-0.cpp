class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        
        for (int i = 1; i < s.length(); ++i)
            res += abs((s[i] - '0') - (s[i - 1] - '0'));
        return res;
    }
};