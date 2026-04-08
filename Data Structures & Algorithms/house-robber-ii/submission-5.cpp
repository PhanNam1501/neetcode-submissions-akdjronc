class Solution {
public:
    int solve(vector<int>& nums, int k, int n) {
        vector<int> dp(n, 0);
        if (nums.size() < 2) return nums[0];
        for (int i = k; i < n; i++) {
            int t1 = i > k ? dp[i-1] : nums[i];
            int t2 = i > k+1 ? dp[i-2] + nums[i] : nums[i];

            dp[i] = max(t1, t2);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int case1 = solve(nums, 1, n);
        int case2 = solve(nums, 0, n-1);

        return max(case1, case2);
    }
};
