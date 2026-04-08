class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        int k = 1;
        while(k*k <= n) {
            sq.push_back(k*k);
            k += 1;
        }


        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < sq.size(); j++) {
                if (sq[j] <= i) {
                    dp[i] = min(dp[i], dp[i - sq[j]] + 1);
                }
            }
        }

        return dp[n];
    }
};