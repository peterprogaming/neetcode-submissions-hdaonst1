class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0; bool allowSpace = true;
        for (int i = s.size() - 1; i >= 0; --i){
            if (s[i] != ' '){
                ++res;
                allowSpace = false;
            }
            if (!allowSpace && s[i] == ' ') break;
        }
        return res;
    }
};