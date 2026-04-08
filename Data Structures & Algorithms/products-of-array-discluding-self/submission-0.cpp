class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1);
        vector<int> suf(n, 1);
        int p = 1;
        for (int i = 1; i < n; i++) {
            p *= nums[i-1];
            pre[i] = p;
        }
        p = 1;
        for (int i = n - 2; i >= 0; i--) {
            p *= nums[i+1];
            suf[i] = p;
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            int t = suf[i] * pre[i];
            res.push_back(t);
        }

        return res;
    }
};
