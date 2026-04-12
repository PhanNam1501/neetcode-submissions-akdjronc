type MyHashMap struct {
	arr []int
}

func Constructor() MyHashMap {
    h := MyHashMap{
		arr: make([]int, 1000001),
	}

	for i := 0; i < 1000001; i++ {
    	h.arr[i] = -1
	}

	return h
}

func (this *MyHashMap) Put(key int, value int) {
	this.arr[key] = value
}

func (this *MyHashMap) Get(key int) int {
    return this.arr[key]
}

func (this *MyHashMap) Remove(key int) {
    this.arr[key] = -1
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */