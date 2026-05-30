type StockSpanner struct {
	st []int
	days []int
}

func Constructor() StockSpanner {
	return StockSpanner {
		st: []int{},
		days: []int{},
	}
}

func (this *StockSpanner) Next(price int) int {
	this.days = append(this.days, price)

	for len(this.st) > 0 && price >= this.days[this.st[len(this.st)-1]] {
		this.st = this.st[:len(this.st)-1]
	}
	res := 0
	if len(this.st) == 0 {
		res = len(this.days)
	} else {
		res = len(this.days)-1-this.st[len(this.st)-1]
	}
	this.st = append(this.st, len(this.days)-1)
	return res
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor()
 * param1 := obj.Next(price)
 */
 