class Solution {
private:
    vector<vector<int>> res;
    vector<vector<int>> index;
    vector<int> s;
    unordered_map<int, bool> used;
    int l;
public:
    void backtrack() {
        if (s.size() == l) {
            index.push_back(s);
        }
        for (int i = 0; i < l; i++) {
            if(used[i] == true) continue;
            s.push_back(i);
            used[i] = true;

            backtrack();

            s.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        l = nums.size();
        sort(nums.begin(), nums.end());
        backtrack();

        for (int i = 0; i < index.size(); i++) {
            vector<int> t;
            for (int j = 0; j < index[i].size(); j++) {
                t.push_back(nums[index[i][j]]);
            }
            res.push_back(t);
        }

        return res;
    }
};
