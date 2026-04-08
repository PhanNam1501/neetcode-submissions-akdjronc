class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        string res = "";
        map<char, int> dict;
        map<char, int> cmp;
        for (int i = 0; i < s.size(); i++) {
            if (dict[s[i]] == 0) {
                res.push_back(s[i]);
            }
            dict[s[i]]++;
            cmp[t[i]]++;
        }

        for (int i = 0; i < res.size(); i++) {
            if (dict[res[i]] != cmp[res[i]]) {
                return false;
            }
        }

        return true;
    }
};
