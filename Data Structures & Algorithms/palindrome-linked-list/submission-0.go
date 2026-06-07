/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func isPalindrome(head *ListNode) bool {
	mid := head
	last := head
	for last.Next != nil && last.Next.Next != nil {
		mid = mid.Next
		last = last.Next.Next
	}
	var mid2 *ListNode
	if last.Next == nil {
		mid2 = mid
	} else {
		mid2 = mid.Next
	}

	prev := &ListNode{}
	for mid2 != nil {
		next := mid2.Next
		mid2.Next = prev
		prev = mid2
		mid2 = next
	}

	for head != nil {
		if head.Next == prev || head == prev {
			if head.Val != prev.Val {
				return false
			}
			break
		}
		if head.Val != prev.Val {
			return false
		}
		head = head.Next
		prev = prev.Next
	}

	return true
}
