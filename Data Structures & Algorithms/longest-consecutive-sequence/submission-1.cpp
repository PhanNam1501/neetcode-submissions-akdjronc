class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 0) return 0;
        int cnt = 1;
        int res = 0;
        int next = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == (next+1)) {
                cnt++;
                next = nums[i];
            } else if (nums[i] > (next+1)) {
                res = max(res, cnt);
                cnt = 1;
                next = nums[i];
            }
        }

        res = max(res, cnt);

        return res;
    }
};
