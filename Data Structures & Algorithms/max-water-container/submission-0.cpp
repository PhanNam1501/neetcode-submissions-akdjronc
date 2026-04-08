class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxx = 0;
        int l = 0;
        int r = n - 1;
        while (l < r) {
            int h = min(heights[l], heights[r]);
            int d = r - l;
            maxx = max(maxx, h * d);
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return maxx;
    }
};
