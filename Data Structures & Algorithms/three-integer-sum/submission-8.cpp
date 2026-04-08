class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) break;
            if (i != 0) {
                if (nums[i] == nums[i-1]) continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int s = nums[i] + nums[j] + nums[k];
                if (s > 0) {
                    k--;
                } else if (s < 0) {
                    j++;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while((j < k) && (nums[j] == nums[j - 1])) {
                        j++;
                    }
                }

            }
        }
        return res;
    }
};
