func maxFrequency(nums []int, k int) int {
	q := []int{}
	maxx := 0
	summ := 0
	n := len(nums)
	sort.Ints(nums)
	for i := 0; i < n; i++ {
		q = append(q, i)
		summ += nums[i]
		for nums[i]*(i-q[0]+1)-summ > k {
			summ -= nums[q[0]]
			q = q[1:]
		} 

		if i >= q[0] {
			maxx = max(i-q[0]+1, maxx)
		}

	} 

	return maxx
}
