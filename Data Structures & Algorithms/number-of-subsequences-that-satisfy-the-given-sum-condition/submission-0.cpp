class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1000000007;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int r = n-1;
        for (int i = 0; i < n; i++) {
            while(i <= r && nums[r] + nums[i] > target) {
                r--;
            }

            if (i <= r) {
                cnt = (cnt + power(2, r-i, mod)) % mod; 
            } else {
                break;
            }

        }

        return cnt;
         
    }

private:
    long long power(int base, int exp, int mod) {
        long long result = 1, b = base;
        while (exp > 0) {
            if (exp & 1) result = (result * b) % mod;
            b = (b * b) % mod;
            exp >>= 1;
        }

        return result;
    }
};