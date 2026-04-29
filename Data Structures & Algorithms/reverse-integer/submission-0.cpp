class Solution {
public:
    int reverse(int x){
        long long num = 0;
        bool neg = false;

        if (x < 0){
            neg = true;
            x = abs(x);
        }

        while (x > 0){
            num = num * 10 + (x % 10);
            x /= 10;
        }

        if (num > INT_MAX) return 0;
        else {
            if (neg) num = -num;

            if (num < INT_MIN) return 0;
            else {
                int res; res = num;
                return res;
            }
        }
    }
};
