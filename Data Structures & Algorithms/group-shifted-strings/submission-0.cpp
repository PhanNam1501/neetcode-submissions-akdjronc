class Solution {
public:
    string getHash(string& s) {
        string hashKey;
        for (int i = 1; i < s.length(); i++) {
            hashKey += (s[i] - s[i - 1] + 26) % 26 + 'a';
        }

        return hashKey;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> myMap;
        for (int i = 0; i < strings.size(); i++) {
            string hashKey = getHash(strings[i]);
            myMap[hashKey].push_back(strings[i]);
        }

        vector<vector<string>> res;
        for (auto m : myMap) {
            res.push_back(m.second);
        }

        return res;
    }
};
