class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element (piles.begin(), piles.end()), k, res = r;
        while (l <= r){
            k = (l + r) / 2;
            long long time = 0;
            for (const auto& i : piles)
                time += ceil (static_cast <double> (i) / k);
            if (time <= h){
                res = k;
                r = k - 1;
            }
            else l = k + 1;
        }
        return res;
    }
};
