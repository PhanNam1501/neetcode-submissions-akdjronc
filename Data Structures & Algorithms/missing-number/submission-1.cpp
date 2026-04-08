class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort()
        int n = nums.size();
        int x = 0;
        for (int i = 0; i <= n; i++) {
            x ^= i;
        }

        for (int i = 0; i < n; i++) {
            x ^= nums[i];
        }

        return x;
    }
};
