func abs(x int) int {
	if x < 0 {
		return x * -1
	}

	return x
}

func asteroidCollision(asteroids []int) []int {
	st := []int{}
	for _, i := range asteroids {
		equal := false
		for len(st) > 0 && st[len(st)-1] > 0 && i < 0 {
			top := st[len(st)-1]
			if abs(top) < abs(i) {
				st = st[:len(st)-1]
			} else if abs(top) == abs(i) {
				st = st[:len(st)-1]
				equal = true
				break
			} else {
				equal = true
				break
			}
		}
		if (!equal) {
			st = append(st, i)
		}
		// if len(st) > 0 && i * st[len(st)-1] > 0 {
		// 	st = append(st, i)
		// }
		// if len(st) == 0 {
		// 	st = append(st, i)
		// }
	}
	

	return st
}
