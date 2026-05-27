func merge(nums1 []int, m int, nums2 []int, n int) {
	l1 := 0
	l2 := 0
	res := make([]int, 0)
	for m > 0 && n > 0 {
		if nums1[l1] < nums2[l2] {
			res = append(res, nums1[l1])
			l1++
			m--
		} else {
			res = append(res, nums2[l2])
			l2++
			n--
		}
	}

	for m > 0 {
		res = append(res, nums1[l1])
		l1++
		m--
	}

	for n > 0 {
		res = append(res, nums2[l2])
		l2++
		n--
	}
	
	copy(nums1, res)
}
