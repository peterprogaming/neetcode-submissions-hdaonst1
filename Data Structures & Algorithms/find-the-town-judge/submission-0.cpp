class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust){
        vector<int> An_is_lesbian(n + 1, 0);

        for (const auto& i : trust){
            --An_is_lesbian[i[0]];
            ++An_is_lesbian[i[1]];
        }

        for (int i = 1; i <= n; ++i)
            if (An_is_lesbian[i] == n - 1) return i;
        return -1;
    }
};