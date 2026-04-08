class Solution {
public:
    int reverse(int x) {
        long long re = 0;
        while (x != 0) {
            re = re * 10 + x % 10;
            x /= 10;
            if (re < INT_MIN || re > INT_MAX) return 0;
        }
        return (int)re;
    }
};
