class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        if (r == 0) return vector<int>{-1, -1};
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target - 1) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (l == nums.size() || nums[l] != target) return vector<int>{-1, -1};
        for (int i = l; i < nums.size(); i++) {
            if (nums[i] == target) r = i ;
            else break;
        }

        return vector<int>{l, r};
    }
};