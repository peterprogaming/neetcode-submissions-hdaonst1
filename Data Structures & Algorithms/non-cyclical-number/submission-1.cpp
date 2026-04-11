class Solution {
public:
    bool isHappy(int n){
        set<int> se; long long sum = 0;

        while (true){
            sum = 0;
            while (n > 0){
                sum += (n % 10) * (n % 10);
                n /= 10;
            }

            if (sum == 1) return true;
            else {
                if (se.count(sum)) return false;
                else se.insert(sum);
            }

            n = sum;
        }
    }
};
