func decodeString(s string) string {
    numStack := []int{}
    strStack := []string{}

    curNum := 0
    curStr := ""

    for _, ch := range s {
        if ch >= '0' && ch <= '9' {
            curNum = curNum*10 + int(ch-'0')
        } else if ch == '[' {
            numStack = append(numStack, curNum)
            strStack = append(strStack, curStr)

            curNum = 0
            curStr = ""
        } else if ch == ']' {
            k := numStack[len(numStack)-1]
            numStack = numStack[:len(numStack)-1]

            prev := strStack[len(strStack)-1]
            strStack = strStack[:len(strStack)-1]

            curStr = prev + strings.Repeat(curStr, k)
        } else {
            curStr += string(ch)
        }
    }

    return curStr
}