/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	cnt1 := 0
	cnt2 := 0
	dA := headA
	dB := headB
	for dA != nil {
		cnt1++
		dA = dA.Next
	}

	for dB != nil {
		cnt2++
		dB = dB.Next
	}

	dA = headA
	dB = headB
	if cnt1 > cnt2 {
		for i := 0; i < cnt1 - cnt2; i++ {
			dA = dA.Next
		}
	} else {
		for i := 0; i < cnt2 - cnt1; i++ {
			dB = dB.Next
		}
	}

	for dA != nil && dB != nil {
		if dA == dB {
			return dA
		}
		dA = dA.Next
		dB = dB.Next
	}

	return nil
}
