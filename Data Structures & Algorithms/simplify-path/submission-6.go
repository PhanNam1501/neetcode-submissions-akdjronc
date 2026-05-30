func simplifyPath(path string) string {
    stack := []string{}
    cur := ""

    for _, c := range path + "/" {
        if c == '/' {
            if cur == ".." {
                if len(stack) > 0 {
                    stack = stack[:len(stack)-1]
                }
            } else if cur != "" && cur != "." {
                stack = append(stack, cur)
            }
            cur = ""
        } else {
            cur += string(c)
        }
    }

    return "/" + strings.Join(stack, "/")
}