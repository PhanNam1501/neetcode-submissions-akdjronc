class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int l = 0;
        int r = 0;
        int cnt = -1;
        while (r < n) {
            if (chars[r] != chars[l]) {
                cnt++;
                chars[cnt] = chars[r-1];
                int t = r-l;
                string s = to_string(t);
                if (t > 1) {
                    int c = cnt;
                    for (int k = 0; k < s.size(); k++) {
                        chars[c+k+1] = s[k];
                        cnt++;
                    }
                }
                // cnt++;
                l = r;
            }
            r++;
        }
        cnt++;
        chars[cnt] = chars[r-1];
        int t = r - l;
        string s = to_string(t);
        if (t > 1) {
            int c = cnt;
            for (int k = 0; k < s.size(); k++) {
                chars[c+k+1] = s[k];
                cnt++;
            }
        }
        l = r;

        return cnt+1;

    }
};