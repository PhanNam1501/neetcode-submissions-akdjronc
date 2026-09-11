class Solution {
public:
    int findMin(vector<int> &nums) {
        // we need to find nums[m] and m int [l, r]
        // for [l, m-1] is false
        // for [m, r]: true
        // e.g: 
        // 3 4 5 6 1 2 
        // l       m r
        // f f f f t t
        // when arr[m] > arr[r]: l = m + 1
        // when arr[m] <= arr[r]: r = m
        // when small, we have [l, l]: -> arr[l] = true
        int l = 0;
        int r = nums.size()-1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        return nums[l];
    }
};
