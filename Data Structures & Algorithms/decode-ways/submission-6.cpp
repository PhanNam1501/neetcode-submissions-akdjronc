class Solution {
public:
    int ctoi(char c) {
        return c - '0';
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        if (s[0] == '0') return 0;
        else {
            dp[0] = 1;
        }


        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                if (ctoi(s[i-1]) > 2 || s[i-1] == '0') return 0;
                if (i < 2) {
                    dp[i] = 1;
                } else {
                    dp[i] = dp[i-2];
                }
            } else {
                if (s[i-1] == '0' || ctoi(s[i-1]) > 2) {
                    dp[i] = dp[i-1];
                } else {
                    if (s[i-1] == '2' && ctoi(s[i]) > 6) {
                        dp[i] = dp[i-1];
                    } else {
                        int t2 = i < 2 ? 1 : dp[i-2];
                        dp[i] = dp[i-1] + t2; 
                    }
                }
            }
        }

        return dp[n-1];
    }
};
