class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for (int i = 0; i < s.length(); ++i){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            if (st.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')) return false;
            if (!st.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')){
                if ((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{')) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};
