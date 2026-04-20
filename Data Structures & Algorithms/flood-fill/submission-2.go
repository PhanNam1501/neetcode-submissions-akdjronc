var dx [4]int
var dy [4]int
var visited [][]bool
var m, n int
func dfs(x, y int, image [][]int, color int, pixel int) {
	visited[x][y] = true
	image[x][y] = color
	for i := 0; i < 4; i++ {
		nx := x + dx[i]
		ny := y + dy[i]

		if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && image[nx][ny] == pixel) {
			dfs(nx, ny, image, color, pixel)
		}
	}
}

func floodFill(image [][]int, sr int, sc int, color int) [][]int {
	pixel := image[sr][sc]

	dx = [4]int{-1, 1, 0, 0}
	dy = [4]int{0, 0, -1, 1}

	m = len(image)
	n = len(image[0])

	visited = make([][]bool, m)
	for i := 0; i < m; i++ {
		visited[i] = make([]bool, n)
	} 
	dfs(sr, sc, image, color, pixel)
	return image
}
