class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> c1(26, 0);
        vector<int> c2(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            c1[s1[i] - 'a']++;
            c2[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (c1[i] == c2[i]) matches++;
        }

        int l = 0;
        for (int i = s1.length(); i < s2.length(); i++) {
            if (matches == 26) {
                return true;
            }

            int idx = s2[i] - 'a';
            c2[idx]++;
            if (c2[idx] == c1[idx]) {
                matches++;
            } else if (c2[idx] == c1[idx] + 1) {
                matches--;
            }

            idx = s2[l] - 'a';
            c2[idx]--;
            if (c2[idx] == c1[idx]) {
                matches++;
            } else if (c2[idx] == c1[idx] - 1) {
                matches--;
            }

            l++;
        }

        return matches == 26;
    }
};
