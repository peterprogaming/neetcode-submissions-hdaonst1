class Solution {
public:
    bool isInterleave(string s1, string s2, string s3){
        int m = s1.length(), n = s2.length();
        vector<bool> dp(n + 1);

        if (m + n != s3.length()) return false;
        if (n < m){
            swap(s1, s2);
            swap(m, n);
        }

        dp[n] = true;
        for (int i = m; i >= 0; --i){
            vector<bool> nxt(n + 1);
            if (i == m) nxt[n] = true;

            for (int j = n; j >= 0; --j){
                if (i < m && s1[i] == s3[i + j] && dp[j]) nxt[j] = true;
                if (j < n && s2[j] == s3[i + j] && nxt[j + 1]) nxt[j] = true;
            }

            dp = nxt;
        }

        return dp[0];
    }
};