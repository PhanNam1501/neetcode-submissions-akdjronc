/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func removeElements(head *ListNode, val int) *ListNode {
	dummy := &ListNode{}
	dummy.Next = head
	prev := dummy
	for head != nil {
		next := head.Next
		if head.Val == val {
			prev.Next = next
		} else {
			prev = head
		}
		head = next
	}
	return dummy.Next
}
