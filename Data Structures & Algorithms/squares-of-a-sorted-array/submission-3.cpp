class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = 0;
        if (nums[0] < 0 && nums[nums.size() - 1] > 0) {
            vector<int> res;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] >= 0) {
                    l = i - 1;
                    r = i;
                    break;
                }
            }

            while (l >= 0 && r < nums.size()) {
                if (nums[l] * nums[l] < nums[r] * nums[r]) {
                    res.push_back(nums[l] * nums[l]);
                    l--;
                } else {
                    res.push_back(nums[r] * nums[r]);
                    r++;
                }
            }

            if (l >= 0) {
                for (int i = l; i >= 0; i--) {
                    res.push_back(nums[i] * nums[i]);
                }
            } else if (r < nums.size()) {
                for (int i = r; i < nums.size(); i++) {
                    res.push_back(nums[i] * nums[i]);
                }
            }

            return res;



        } else {
            vector<int> res;
            if (nums[nums.size() - 1] <= 0) {
                for (int i = nums.size()-1; i >= 0; i--) {
                    res.push_back(nums[i] * nums[i]);
                }
                return res;
            }
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = nums[i] * nums[i];
            }
            return nums;
        }
    }
};