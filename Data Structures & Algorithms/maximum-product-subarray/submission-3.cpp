class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {0,0}); //first: max, second: min
        int res = 0;
        dp[0] = {nums[0], nums[0]};
        res = dp[0].first;

        for (int i = 1 ; i < n; i++) {
            int t1 = nums[i] * dp[i-1].first;
            int t2 = nums[i] * dp[i-1].second;
            dp[i].first = max(max(t1, t2), nums[i]);
            dp[i].second = min(min(t1, t2), nums[i]);
            res = max(dp[i].first, res);
        }

        return res;
    }
};
