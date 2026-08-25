class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string, bool> check;
        for (int i = 0; i < wordDict.size(); i++) {
            check[wordDict[i]] = true;
        }
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                string t = s.substr(j-1, i-j+1);
                dp[i] = dp[j-1] && check[t];
                if (dp[i] == true) break;
            }
        }

        return dp[n];
    }
};
