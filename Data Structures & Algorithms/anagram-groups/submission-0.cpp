class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> myMap;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++) {
            string t = strs[i];
            sort(t.begin(), t.end());
            myMap[t].push_back(i);
        }
    
        for (auto &p : myMap) {
            vector<string> group;
            for (int idx : p.second) {
                group.push_back(strs[idx]);
            }
            res.push_back(group);
        }

        return res;
    }
};
