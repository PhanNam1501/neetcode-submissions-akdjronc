class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++) {
            if (i == 0) {
                vector<int> t = {1};
                res.push_back(t);
            } else if (i == 1) {
                vector<int> t = {1, 1};
                res.push_back(t);
            } else {
                vector<int> t = res[res.size() - 1];
                vector<int> r;
                r.push_back(1);
                for (int j = 1; j < t.size(); j++) {
                    r.push_back(t[j] + t[j - 1]);
                }
                r.push_back(t[t.size() - 1]);
                res.push_back(r);
            }
        }

        return res;
    }
};