class Solution {
public:
    vector <string> res;
    vector<string> generateParenthesis(int n) {
        string s;
        backtrack(0, 0, n, res, s);
        return res;
    }
    void backtrack(int fuga, int close, int n, vector <string>& res, string& s){
        if (fuga == close && fuga == n){
            res.push_back(s);
            return;
        }
        if (fuga < n){
            s += '(';
            backtrack(fuga + 1, close, n, res, s);
            s.pop_back();
        }
        if (close < fuga){
            s += ')';
            backtrack(fuga, close + 1, n, res, s);
            s.pop_back();
        }
    }
};
