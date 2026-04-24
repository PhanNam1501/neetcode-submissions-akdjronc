func maxProduct(nums []int) int {
    n := len(nums)
	dp := make([]int, n+1)
	minn := make([]int, n+1)
	dp[0] = 1
	minn[0] = 1
	res := -2147483648
	for i := 1; i <= n; i++ {
		t1 := dp[i-1] * nums[i-1]
		t2 := minn[i-1] * nums[i-1]
		t := nums[i-1]
		dp[i] = max(t, max(t1, t2))
		res = max(res, dp[i])
		minn[i] = min(t, min(t1, t2))
	}

	return res
}
