class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> myMap;
        unordered_map<char, int> check;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            auto it = myMap.find(s[i]);
            auto it1 = check.find(t[i]);
            if (it1 != check.end()) {
                if (it1->second != s[i]) {
                    return false;
                }
            }
            if (it != myMap.end()) {
                if (it->second != t[i]) {
                    return false;
                } 
            } else {
                myMap[s[i]] = t[i];
                check[t[i]] = s[i];
            }
        }

        return true;
    }
};