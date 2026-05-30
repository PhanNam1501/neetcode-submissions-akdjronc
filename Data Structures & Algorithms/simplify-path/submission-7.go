func simplifyPath(path string) string {
    st := []string{}
	cur := ""

	for _, c := range path + "/" {
		if c == '/' {
			if cur == ".." {
				if len(st) > 0 {
					st = st[:len(st)-1]
				}
			} else if cur != "" && cur != "." {
				st = append(st, cur)
			}

			cur = ""
		} else {
			cur += string(c)
		}
	}

	return "/" + strings.Join(st, "/")
}