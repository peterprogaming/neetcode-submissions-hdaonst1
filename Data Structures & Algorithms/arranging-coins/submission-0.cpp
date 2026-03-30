class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 1, r = n, mid, c, res = LLONG_MIN;

        while (l <= r){
            mid = l + (r - l) / 2;
            c = (mid * (mid + 1)) / 2;

            if (c > n) r = mid - 1;
            else {
                l = mid + 1;
                res = max(res, mid);
            }
        }
        return res;
    }
};