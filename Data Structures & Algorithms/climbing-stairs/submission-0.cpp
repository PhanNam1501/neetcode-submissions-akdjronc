class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int f1 = climbStairs(n-1);
        int f2 = climbStairs(n-2);

        return f1 + f2;
    }
};
