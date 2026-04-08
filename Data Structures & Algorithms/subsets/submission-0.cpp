class Solution {
private:
    vector<vector<int>> res;
    vector<int> s;
    unordered_map<int, bool> used;
public:
    void backtrack(int l) {
        int lastIndex = s.empty() ? -1 : s.back();
        for (int i = lastIndex + 1; i < l; i++) {
            s.push_back(i);
            res.push_back(s);
            backtrack(l);
            s.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums.size());
        vector<vector<int>> re;
        vector<int> o;
        re.push_back(o);
        for (int i = 0; i < res.size(); i++) {
            vector<int> t;
            for (int j = 0; j < res[i].size(); j++) {
                t.push_back(nums[res[i][j]]);
            }
            re.push_back(t);
        }
        return re;
    }
};
