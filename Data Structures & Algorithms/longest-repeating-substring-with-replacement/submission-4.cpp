class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int maxx = 0;
        int l = 0;
        int maxf = 0;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            maxf = max(maxf, m[s[i]]);
            while((i - l + 1) - maxf > k) {
                m[s[l]]--;
                l++;
            }

            maxx = max(maxx, i - l + 1);
        }

        return maxx;
    }
};
