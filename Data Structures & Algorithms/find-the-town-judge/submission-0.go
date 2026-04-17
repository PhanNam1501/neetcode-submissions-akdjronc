func findJudge(n int, trust [][]int) int {
	first := make([]bool, n+1)
	second := make(map[int]int)
	for i := 0; i < len(trust); i++ {
		first[trust[i][0]] = true
		second[trust[i][1]]++
	}

	for i := 1; i <= n; i++ {
		if !first[i] && second[i] == n-1 {
			return i
		}
	}

	return -1
}
