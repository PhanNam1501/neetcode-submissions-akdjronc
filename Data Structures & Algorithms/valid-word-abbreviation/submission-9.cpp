class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.size();
        int n = abbr.size();
        int i = 0;
        int j = 0;

        while(i < m && j < n) {
            if (abbr[j] == '0') return false;
            if (isalpha(abbr[j])) {
                if (word[i] != abbr[j]) return false;
                i++;
                j++;
            } else {
                string sub = "";
                while(j < n && isdigit(abbr[j])) {
                    sub += abbr[j];
                    j++;
                }
                int p = 0;
                for (int k = 0; k < sub.length(); k++) {
                    char c = sub[k];
                    int x = c - '0';
                    p += pow(10, sub.size() - k - 1) * x;
                }
                i+=p;
            }
        }

        return i == m && j == n;
    }
};