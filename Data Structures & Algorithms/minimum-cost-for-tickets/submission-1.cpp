class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int idx = 0;
        int n = days.size();
        int target = days[n-1];
        vector<int> dp(target+1, INT_MAX);
        dp[0] = 0;
        bool end = false;
        for (int i = 1; i <= target; i++) {
            if (!end && (i == days[idx])) {
                int t1 = dp[i-1] + costs[0];
            
            int t2 = dp[max(0, i - 7)] + costs[1];
            
            int t3 = dp[max(0, i - 30)] + costs[2];

            dp[i] = min({t1, t2, t3});
                idx++;
                if (idx == n) end = true;
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[target];
    }
};