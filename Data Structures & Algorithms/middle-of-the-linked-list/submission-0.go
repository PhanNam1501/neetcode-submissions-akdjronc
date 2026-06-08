/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func middleNode(head *ListNode) *ListNode {
	last := head
	mid := head
	for last.Next != nil && last.Next.Next != nil {
		mid = mid.Next
		last = last.Next.Next
	}

	if last.Next != nil {
		return mid.Next
	}
	return mid
}
