var res int
func backtrack(nums []int, start int, curXor int) {
	res += curXor

	for i := start; i < len(nums); i++ {
		backtrack(nums, i+1, curXor^nums[i])
	}
}

func subsetXORSum(nums []int) int {
	res = 0
	backtrack(nums, 0, 0)
	return res
}