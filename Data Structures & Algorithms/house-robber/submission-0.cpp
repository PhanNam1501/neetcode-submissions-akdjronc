class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            int t1 = i > 0 ? dp[i-1] : 0;
            int t2 = i > 1 ? dp[i-2] : 0;
            dp[i] = max(t1, t2 + nums[i]);
        }

        return dp[n-1];
    }
};
