type MinStack struct {
	stack []int
	minn int 
}

func Constructor() MinStack {
	return MinStack {
		stack: []int{}, // include the distance of this object to nearest min of stack
		minn: math.MaxInt64,
	}
}

func (this *MinStack) Push(val int) {
	if len(this.stack) == 0 {
		this.stack = append(this.stack, 0)
		this.minn = val
	} else {
		this.stack = append(this.stack, val - this.minn)
		if val < this.minn {
			this.minn = val
		}
	}
}

func (this *MinStack) Pop() {
	if len(this.stack) == 0 {
        return
    }
	val := this.stack[len(this.stack)-1]
	this.stack = this.stack[:len(this.stack)-1]
	if val < 0 {
		this.minn = this.minn - val
	}
}

func (this *MinStack) Top() int {
	top := this.stack[len(this.stack)-1]
    if top > 0 {
        return top + this.minn
    }
    return this.minn
}

func (this *MinStack) GetMin() int {
	return this.minn
}
