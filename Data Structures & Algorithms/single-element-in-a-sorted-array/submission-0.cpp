class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = nums.size()-1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            bool c1 = m > 0 ? nums[m] > nums[m-1] : true;
            bool c2 = m < n-1 ? nums[m] < nums[m+1] : true;
            if (c1 && c2) return nums[m];
            if (m % 2 == 0) {
                if (m < nums.size()-1 && nums[m] == nums[m+1]) {
                    l = m + 2;
                } else {
                    r = m - 2;
                }
            } else {
                if (m < nums.size()-1 && nums[m] != nums[m+1]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};