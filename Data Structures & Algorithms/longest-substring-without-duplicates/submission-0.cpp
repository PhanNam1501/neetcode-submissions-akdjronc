class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> m;
        int maxx = 0;
        int l = 0;
        for (int i = 0 ; i < n; i++) {
            if (m.find(s[i]) != m.end()) {
                l = max(l, m[s[i]] + 1);
            }
            m[s[i]] = i;
            maxx = max(maxx, i - l + 1);
        }

        return maxx;
    }   
};
