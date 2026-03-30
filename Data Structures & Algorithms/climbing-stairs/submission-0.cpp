class Solution {
public:
    int climbStairs(int n) {
        vector <int> steps(n + 1);
        steps[0] = 0;
        steps[1] = 1;
        steps[2] = 2;
        for (int i = 3; i < steps.size(); ++i)
            steps[i] = steps[i - 1] + steps[i - 2];
        return steps[n];
    }
};
