var dx [4]int
var dy [4]int
var per int

func dfs(x, y int, grid [][]int, visited [][]bool, row, col int) {
    visited[x][y] = true
    total := 4

    for i := 0; i < 4; i++ {
        nx := x + dx[i]
        ny := y + dy[i]

        if nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1 {
            total -= 1
        }

        if nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny] && grid[nx][ny] == 1 {
            dfs(nx, ny, grid, visited, row, col)
        }
    }

    per += total
}

func islandPerimeter(grid [][]int) int {
    dx = [4]int{-1, 1, 0, 0}
    dy = [4]int{0, 0, -1, 1}
    per = 0
    islands := make([][]int, 0)

    row := len(grid)
    col := len(grid[0])

    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid[i]); j++ {
            if (grid[i][j] == 1) {
                islands = append(islands, []int{i, j})
            }
        }
    }

    visited := make([][]bool, 0)
    for i := 0; i < len(grid); i++ {
        v := make([]bool, len(grid[i]))
        visited = append(visited, v)
    }

    for _, island := range islands {
        if (visited[island[0]][island[1]]) {
            continue;
        }

        dfs(island[0], island[1], grid, visited, row, col)
    }

    return per
}
