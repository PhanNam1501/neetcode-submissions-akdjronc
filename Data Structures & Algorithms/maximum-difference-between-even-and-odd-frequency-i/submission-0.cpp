class Solution {
public:
    int maxDifference(string s) {
        int maxx = 0;
        int minn = INT_MAX;
        sort(s.begin(), s.end());
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                count += 1;
            } else {
                if (s[i] == s[i-1]) {
                    count++;
                } else {
                    if (count % 2 == 1) {
                        maxx = max(maxx, count);
                    } else {
                        minn = min(minn, count);
                    }
                    count = 1;
                }
            }
        }

        if (count % 2 == 1) {
                maxx = max(maxx, count);
        } else {
                minn = min(minn, count);
        }

        return maxx- minn;
    }
};