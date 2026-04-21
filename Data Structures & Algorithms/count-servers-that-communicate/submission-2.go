
func countServers(grid [][]int) int {
	res := 0

	m := len(grid)
	n := len(grid[0])

	rowCount := make([]int, m)
	colCount := make([]int, n)
	
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				rowCount[i]++
				colCount[j]++
			}
		}
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				if rowCount[i] > 1 || colCount[j] > 1 {
					res++
				} 
			}
		}
	}

	return res
}
