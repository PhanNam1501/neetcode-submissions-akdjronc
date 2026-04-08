class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        int r = 1;
        while (l < r && r < nums.size()) {
            if (nums[l] == 0 && nums[r] != 0) {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++;
                r++;
            } else if (nums[l] == 0 && nums[r] == 0) {
                r++;
            } else {
                l++;
                r++;
            }

        }
    }

};