type MinStack struct {
	arr []int
}

func Constructor() MinStack {
	return MinStack {
		arr: make([]int, 0),
	}
}

func (this *MinStack) Push(val int) {
	this.arr = append(this.arr, val)
}

func (this *MinStack) Pop() {
	this.arr = this.arr[:len(this.arr)-1]

}

func (this *MinStack) Top() int {	
	return this.arr[len(this.arr)-1]
}

func (this *MinStack) GetMin() int {
	minn := 2147483648
	for _, i := range(this.arr) {
		minn = min(minn, i)
	}

	return minn
}
