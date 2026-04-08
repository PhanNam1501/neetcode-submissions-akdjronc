var used []bool
var n int
var res [][]int
var cur []int
func backtrack(nums []int) {
	for i := 0; i < n; i++ {
		if i > 0 && nums[i] == nums[i-1] && !used[i-1] {
			continue
		}
		if used[i] {
			continue
		}
		cur = append(cur, nums[i])
		used[i] = true
		if len(cur) == n {
			tmp := make([]int, len(cur))
			copy(tmp, cur)
			res = append(res, tmp)
		} else {
			backtrack(nums)
		}
		cur = cur[:len(cur)-1]
		used[i] = false
	}
}

func permuteUnique(nums []int) [][]int {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j] 
	})
	cur = []int{}
	res = [][]int{}
	n = len(nums)
	used = make([]bool, n)
	backtrack(nums)
	return res
}
