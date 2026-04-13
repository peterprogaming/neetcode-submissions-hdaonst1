class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        sort(strs.begin(), strs.end());
        string start = strs.front(), last = strs.back();
        int len = min(start.length(), last.length()), i = 0;

        while (i < len && start[i] == last[i]) ++i;
        return start.substr(0, i);
    }
};