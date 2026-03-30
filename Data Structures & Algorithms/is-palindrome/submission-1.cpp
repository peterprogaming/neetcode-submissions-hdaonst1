class Solution {
public:
    bool isPalindrome(string s) {
        string Dui = ""; int i, j;
        for (i = 0; i < s.length(); ++i)
            if (isalnum(s[i])) Dui += tolower(s[i]);
        i = 0, j = Dui.length() - 1;
        while (i <= j){
            if (Dui[i] != Dui[j]) return false;
            ++i; --j;
        }
        return true;
    }
};
