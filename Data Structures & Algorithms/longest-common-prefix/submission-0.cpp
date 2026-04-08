class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string res = "";
        for (int i = 0; i < (strs[0].size()); i++) {
            if (strs[0][i] == strs[strs.size() - 1][i]) {
                res.push_back(strs[0][i]);
            } else {
                break;
            }
        }

        return res;
    }
};