class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, m, res;
        while (l <= r){
            m = l + (r - l) / 2;
            if ((long long) m * m == x) return m;
            if ((long long) m * m > x) r = m - 1;
            if ((long long) m * m < x){
                l = m + 1;
                res = m;
            }
        }
        return res;
    }
};