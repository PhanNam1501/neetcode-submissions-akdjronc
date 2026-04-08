class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        int count = 0;
        int count1 = 0;
        for (int i = 0; i < n; i++) {
            count += nums[i];
            count1 += nums[n - i - 1];
            pre[i] = count;
            suf[n - i - 1] = count1;
        }

        for (int i = 0; i < n; i++) {
            if (pre[i] == suf[i]) {
                return i;
            }
        }

        return -1;
    }
};