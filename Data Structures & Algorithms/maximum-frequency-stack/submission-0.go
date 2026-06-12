type FreqStack struct {
	cnt    map[int]int
    stacks map[int][]int
    maxCnt int
}

func Constructor() FreqStack {
	return FreqStack {
		cnt: make(map[int]int),
		stacks: make(map[int][]int),
		maxCnt: 0,
	}
}

func (this *FreqStack) Push(val int) {
	freq := this.cnt[val]
	this.cnt[val] = freq + 1
	this.stacks[freq+1] = append(this.stacks[freq+1], val)
	this.maxCnt = max(this.maxCnt, freq + 1)
}

func (this *FreqStack) Pop() int {
	maxx := this.maxCnt
	if len(this.stacks[maxx]) == 0 {
		maxx--
		this.maxCnt--
	}
	last := this.stacks[maxx][len(this.stacks[maxx])-1]
	this.stacks[maxx] = this.stacks[maxx][:len(this.stacks[maxx])-1]
	this.cnt[last]--
	return last
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * obj := Constructor()
 * obj.Push(val)
 * param2 := obj.Pop()
 */
 