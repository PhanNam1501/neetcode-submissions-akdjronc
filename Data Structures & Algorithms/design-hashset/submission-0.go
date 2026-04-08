type MyHashSet struct {
    set []int
}

func Constructor() MyHashSet {
    return MyHashSet{}
}

func (this *MyHashSet) Add(key int) {
    if !this.Contains(key) {
        this.set = append(this.set, key)
    }
}

func (this *MyHashSet) Remove(key int) {
    for i := 0; i < len(this.set); i++ {
        if key == this.set[i] {
            this.set = append(this.set[:i], this.set[i+1:]...)
            return
        }
    }
}

func (this *MyHashSet) Contains(key int) bool {
    for i := 0; i < len(this.set); i++ {
        if key == this.set[i] {
            return true
        }
    }

    return false
}
