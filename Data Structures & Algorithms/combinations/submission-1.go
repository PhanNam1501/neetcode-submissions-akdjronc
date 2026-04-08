var res [][]int
var cur []int
func backtrack(n, k int) {
    var lastNum int
	if len(cur) == 0 {
		lastNum = 0
	} else {
		lastNum = cur[len(cur)-1]
	}

    for i := lastNum+1; i <= n; i++ {
        cur = append(cur, i)
        if len(cur) == k {
            tmp := make([]int, len(cur))
            copy(tmp, cur)
            res = append(res, tmp)
        } else {
            backtrack(n, k)
        }
        cur = cur[:len(cur)-1]
    }
}

func combine(n int, k int) [][]int {
    res = [][]int{}
	cur = []int{}
    backtrack(n, k)
    return res
}
