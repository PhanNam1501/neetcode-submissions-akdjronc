func wordBreak(s string, wordDict []string) bool {
    m := make(map[string]bool)
	for i := 0; i < len(wordDict); i++ {
		m[wordDict[i]] = true
	}
	m[""] = true
	n := len(s)

	dp := make([]bool, n+1)
	dp[0] = true

	for i := 1; i <= n; i++ {
		for _, word := range wordDict {
			if i >= len(word) {
				part := s[i-len(word):i]
				if m[part] && dp[i - len(word)]{
					dp[i] = true
					break
				}
			}
		}
	}

	return dp[n]
}
