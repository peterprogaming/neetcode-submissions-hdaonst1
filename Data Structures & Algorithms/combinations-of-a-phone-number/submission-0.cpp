class Solution {
public:
    vector <string> digitChar = {"", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"};
    vector <string> res;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        string cur;
        backtrack(0, "", digits);
        return res;
    }
    void backtrack(int i, string cur, string& digits){
        if (cur.size() == digits.size()){
            res.push_back(cur);
            return;
        }
        string chars = digitChar[digits[i] - '0'];
        for (char c : chars)
            backtrack(i + 1, cur + c, digits);
    }
};
