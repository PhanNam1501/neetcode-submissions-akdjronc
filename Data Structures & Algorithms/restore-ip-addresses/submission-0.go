var res []string
var idx []int
var cur []string

func backtrack(str string) {
	lastIdx := -1
	if len(idx) != 0 {
		lastIdx = idx[len(idx)-1]
	}

	if len(cur) == 4 {
		if lastIdx == len(str)-1 {
			s1 := ""
			for j := 0; j < 4; j++ {
				s1 += cur[j]
				if j < 3 {
					s1 += "."
				}
			}
			res = append(res, s1)
		}
		return
	}

	for i := 0; i <= 2; i++ {
		if lastIdx+1+i > len(str)-1 {
			break
		}

		part := str[lastIdx+1 : lastIdx+2+i]

		if len(part) > 1 && part[0] == '0' {
			continue
		}

		num, err := strconv.Atoi(part)
		if err != nil {
			continue
		}
		if num > 255 {
			continue
		}

		cur = append(cur, part)
		idx = append(idx, lastIdx+1+i)

		backtrack(str)

		cur = cur[:len(cur)-1]
		idx = idx[:len(idx)-1]
	}
}

func restoreIpAddresses(s string) []string {
	res = []string{}
	idx = []int{}
	cur = []string{}
	backtrack(s)
	return res
}