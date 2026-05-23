/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Neighbors []*Node
 * }
 */


func cloneGraph(node *Node) *Node {
    if node == nil {
        return nil
    }

    visited := make(map[*Node]*Node)
    var dfs func(*Node) *Node

    dfs = func(curr *Node) *Node {
        if clone, found := visited[curr]; found {
            return clone
        }

        cloneNode := &Node{Val: curr.Val}
        visited[curr] = cloneNode
        for _, neg := range curr.Neighbors {
            cloneNode.Neighbors = append(cloneNode.Neighbors, dfs(neg))
        }

        return cloneNode
    }

    return dfs(node)
}
