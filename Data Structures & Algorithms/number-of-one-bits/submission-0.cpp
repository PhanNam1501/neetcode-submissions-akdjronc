class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 1;
        int cnt = 0;
        for (int i = 0; i < 31; i++) {
            if (c & n) cnt++;
            c <<= 1;
        }
        return cnt;
    }
};
