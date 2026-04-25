func canPartition(nums []int) bool {
	part := 0
	m := make(map[int]bool)
	for _, num := range nums {
		part += num
		m[num] = true
	}

	if part%2==0 {
		part = part / 2
	} else {
		return false
	}

	dp := make([]bool, part+1)
	dp[0] = true

	for _, num := range nums {
		for j := part; j >= num; j-- { 
            if dp[j-num] {
                dp[j] = true
            }
        }
	} 

	return dp[part]
}
