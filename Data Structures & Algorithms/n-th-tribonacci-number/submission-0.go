func tribonacci(n int) int {
	dp := make([]int, n+1)

	
	for  i := 0 ; i <= n; i++ {
		if i == 0 {
			dp[i] = 0
		} else if i < 3 {
			dp[i] = 1
		} else {
			dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		}
	}
	
	return dp[n]
}
