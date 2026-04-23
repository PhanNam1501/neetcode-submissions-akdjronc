func longestPalindrome(s string) string {
    n := len(s)
	start, length := 0, 0

	dp := make([][]bool, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]bool, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j <= i; j++ {
			if s[i] == s[j] && (i - j <= 2 || dp[i-1][j+1]) {
				dp[i][j] = true
				if i-j+1 > length {
					length = i-j+1
					start = j
				}
			}
		}
	}

	res := ""
	for i := 0; i < length; i++ {
		res += string(s[start])
		start += 1 
	}

	return res
}
