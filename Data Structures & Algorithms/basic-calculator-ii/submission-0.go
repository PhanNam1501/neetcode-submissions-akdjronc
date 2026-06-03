func calculate(s string) int {
	// logic : always add lastNum to res, lastNum can be flex by the op 
    res := 0
    lastNum := 0
    curNum := 0
    op := '+'

    for i := 0; i <= len(s); i++ {
        if i < len(s) && s[i] == ' ' {
            continue
        }

        if i < len(s) && s[i] >= '0' && s[i] <= '9' {
            curNum = curNum*10 + int(s[i]-'0')
            continue
        }

        switch op {
        case '+':
            res += lastNum
            lastNum = curNum
        case '-':
            res += lastNum
            lastNum = -curNum
        case '*':
            lastNum *= curNum
        case '/':
            lastNum /= curNum
        }

        if i < len(s) {
            op = rune(s[i])
        }

        curNum = 0
    }

    return res + lastNum
}