class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxx = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count += 1;
            } else {
                maxx = max(maxx, count);
                count = 0;
            }
        }

        if (nums[nums.size() - 1] == 1) {
            maxx = max(maxx, count);
        }

        return maxx;
    }
};