var dx [4]int
var dy [4]int
var visited [][]bool
var res int
var m, n int

func dfs(x, y int, grid [][]byte) {
	visited[x][y] = true
	for i := 0; i < 4; i++ {
		nx := x + dx[i]
		ny := y + dy[i]

		if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1' && !visited[nx][ny]) {
			dfs(nx, ny, grid)
		}
	}
	
}

func numIslands(grid [][]byte) int {
    dx = [4]int{-1, 1, 0, 0}
	dy = [4]int{0, 0, -1, 1}
	res = 0
	n = len(grid)
	m = len(grid[0])

	visited = make([][]bool, n)
	for i := 0; i < n; i++ {
		visited[i] = make([]bool, m)
	}

	openings := make([][]int, n)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if (grid[i][j] == '1') {
				openings[i] = append(openings[i], j)
			}
		}
	}

	for i := 0; i < n; i++ {
		for _, v := range openings[i] {
			if !visited[i][v] {
				dfs(i, v, grid)
				res++
			}
		}
	}

	return res
}
