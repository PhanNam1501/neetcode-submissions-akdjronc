var dx [4]int 
var dy [4]int 
var res int
var m, n int
var visited [][]bool

func dfs(x, y int, grid [][]int) {
	visited[x][y] = true
	res++
	for i := 0; i < 4; i++ {
		nx := x + dx[i]
		ny := y + dy[i]

		if nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && !visited[nx][ny] {
			dfs(nx, ny, grid) 
		}
	}
}

func maxAreaOfIsland(grid [][]int) int {
    res = 0
	m = len(grid)
	n = len(grid[0])

	dx = [4]int{-1, 1, 0, 0}
	dy = [4]int{0, 0, -1, 1}

	openings := make([][]int, m)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				openings[i] = append(openings[i], j)
			}
		}
	}

	visited = make([][]bool, m)
	for i := 0; i < m; i++ {
		visited[i] = make([]bool, n)
	}

	r := 0

	for i := 0; i < m; i++ {
		for _, v := range openings[i] {
			if !visited[i][v] {
				dfs(i, v, grid)
				r = max(r, res)
				res = 0
			}
		}
	}

	return r
}
