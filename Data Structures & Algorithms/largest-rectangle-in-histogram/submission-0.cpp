class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        int n = heights.size(), maxA = 0, top = -1;
        int id[1000], h[1000];

        for (int i = 0; i < n; ++i){
            int height = heights[i], start = i;

            while (top >= 0 && h[top] > height){
                maxA = max(maxA, h[top] * (i - id[top]));
                start = id[top--];
            }

            h[++top] = height;
            id[top] = start;
        }

        while (top >= 0) maxA = max(maxA, h[top] * (n - id[top--]));
        return maxA;
    }
};