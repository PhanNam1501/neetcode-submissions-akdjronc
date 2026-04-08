class Solution {
public:
    int lengthOfLastWord(string s) {
        int maxx = 0;
        int count  = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                count = 0;
                continue;
            } else {
                count++;
            }
            maxx = count;
        }

        if (s[s.size() - 1] != ' ') {
            maxx = count;
        }

        return maxx;
    }
};