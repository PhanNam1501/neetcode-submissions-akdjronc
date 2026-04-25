func lengthOfLIS(nums []int) int {
    n := len(nums)
	dp := make([]int, n+1)

	dp[0] = 0
	for i := 1; i <= n; i++ {
		dp[i] = 1
	}
	for i := 2; i <= n; i++ {
		for j := 0; j < i; j++ {
			if nums[i-1] > nums[j] {
				dp[i] = max(dp[i], dp[j+1] + 1)
			}
		}
	}

	res := 0
	for _, r := range dp {
		res = max(res, r)
	}
	return res
}
