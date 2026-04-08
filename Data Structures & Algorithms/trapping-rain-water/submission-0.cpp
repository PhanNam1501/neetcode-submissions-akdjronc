class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n, -1);
        vector<int> suf(n, n);
        int h = 0;

        for (int i = 1 ; i < n; i++) {
            if (height[i] < height[h]) {
                pre[i] = h;
            } else {
                h = i;
            }
        }
        h = n-1;
        for (int i = n-2; i >= 0; i--) {
            if (height[i] < height[h]) {
                suf[i] = h;
            } else {
                h = i;
            }
        }
        int total = 0;
        for (int i = 0; i < n; i++) {
            if ((pre[i] == -1) || (suf[i] == n)) continue;
            int hi = min(height[pre[i]], height[suf[i]]);
            total += (hi - height[i]);
        }

        return total;
    }
};
