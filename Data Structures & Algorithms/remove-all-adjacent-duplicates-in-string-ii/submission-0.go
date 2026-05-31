func removeDuplicates(s string, k int) string {
	strSt := []rune{}
	numSt := []int{}
	for _, x := range s {
		for len(strSt) > 0 && numSt[len(numSt)-1] == k {
			for j := 0; j < k; j++ {
				strSt = strSt[:len(strSt)-1]
				numSt = numSt[:len(numSt)-1]
			}
		}

		if len(strSt) > 0 && x == strSt[len(strSt)-1] {
			numSt = append(numSt, numSt[len(numSt)-1]+1)
		} else {
			numSt = append(numSt, 1)
		}
		strSt = append(strSt, x)
	}

	for len(strSt) > 0 && numSt[len(numSt)-1] == k {
		for j := 0; j < k; j++ {
			strSt = strSt[:len(strSt)-1]
			numSt = numSt[:len(numSt)-1]
		}
	}

	return string(strSt)
}
