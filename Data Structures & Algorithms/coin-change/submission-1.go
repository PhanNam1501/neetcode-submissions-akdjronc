func coinChange(coins []int, amount int) int {
	// maxInt := int(^uint(0) >> 1)
    n := len(coins)

	dp := make([]int, amount + 1)
	for i := 1; i <= amount; i++ {
		dp[i] = -1
	}
	dp[0] = 0
	for i := 1; i <= amount; i++ {
		for j := 0; j < n; j++ {
			if i >= coins[j] {
				if dp[i - coins[j]] == -1 {
					continue
				}

				if dp[i] == -1 {
					dp[i] = dp[i - coins[j]] + 1
				} else {
					dp[i] = min(dp[i], dp[i - coins[j]] + 1) 
				}
			}
		}
	}

	return dp[amount]
}
