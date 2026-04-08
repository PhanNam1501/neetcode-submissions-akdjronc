class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        int i = 0;
        int j = 0;

        string res = "";
        while (i < m && j < n) {
            res+= word1[i];
            res+= word2[j];
            i++;
            j++;
        }
        if (i < m) {
            for (int k = i; k < m; k++) {
                res += word1[k];
            }
        } else if (j < n) {
            for (int k = j; k < n; k++) {
                res += word2[k];
            }
        }

        return res;
    }
};