class Solution {
public:
    int binarysearch(vector<int> &nums, int target) {
        int l = 0; 
        int r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target) l = m + 1;
            else r = m;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int l = binarysearch(nums, target-1);
        int r = binarysearch(nums, target);
        if (l <= r-1) return vector<int>{l, r-1};
        return vector<int>{-1, -1};
    }
};