class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for (int i = 0; i <= n; i++) {
            int cnt = 0;
            int j = i;
            while(j!=0) {
                if (1&j) cnt++;
                j>>=1;
            }
            res[i] = cnt;
        }

        return res;
    }
};
