func removeDuplicates(nums []int) int {
    n := len(nums)
	res := n
	m := make(map[int]int)
	l := 0
	for i := 0; i < n; i++ {
		m[nums[i]]++
		if m[nums[i]] > 2 {
			res--
			continue
		} 
		nums[l] = nums[i]
		l++
	}
	return res
}