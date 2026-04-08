class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int x_all = 0;
        for (int i = 0; i < n; i++) {
            x_all ^= nums[i];
        }

        int diff = 1;
        while((diff & x_all) == 0) {
            diff = diff << 1;
        }
        int a = 0;
        int b = 0;
        for (int i = 0; i < n; i++) {
            if (diff & nums[i]) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }

        return {a, b};

    }
};