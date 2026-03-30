class Solution {
public:
    int countSeniors(vector<string>& details) {
        string s; int age = 0, res = 0;
        for (int i = 0; i < details.size(); ++i){
            s = details[i]; age = 0;
            age = (s[11] - '0') * 10 + (s[12] - '0');
            if (age > 60) ++res;
        }
        return res;
    }
};