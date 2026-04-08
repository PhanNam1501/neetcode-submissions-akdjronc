class Solution {
private:
    vector<vector<int>> index;
    vector<vector<int>> res;
    vector<int> s;
    vector<int> t;
    unordered_map<int, bool> used;
public:
    void backtrack() {
        int lastIndex = s.empty() ? -1 : s.back();
        for (int i = lastIndex+1; i < t.size(); i++) {
            if (used[i] == true) continue;
            if (i > 0 && t[i] == t[i - 1] && !used[i - 1])
            continue;
            //if (i > 0 && t[i] == t[i-1] && s.size()==0) continue;
            used[i] = true;
            s.push_back(i);
            index.push_back(s);
            if (s.size() < t.size()) {
                backtrack();
            } 
            s.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        t = nums;
        res.push_back(s);
        backtrack();
        for (int i = 0; i < index.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < index[i].size(); j++) {
                temp.push_back(nums[index[i][j]]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
