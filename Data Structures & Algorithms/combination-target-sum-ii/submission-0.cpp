class Solution {
private:
    vector<vector<int>> index;
    vector<vector<int>> res;
    vector<int> s;
    int summ = 0;
    int t;
    vector<int> samp;
    unordered_map<int, bool> used;
public:
    void backtrack() {
        int lastIndex = s.empty() ? -1 : s.back();
        for (int i = lastIndex+1; i < samp.size(); i++) {
            if (used[i] == true) continue;
            if (i > 0 && samp[i] == samp[i - 1] && !used[i - 1])
            continue;

            s.push_back(i);
            used[i] = true;
            summ += samp[i];

            if (summ >= t) {
                if (summ == t) {
                    index.push_back(s);
                }
            } else {
                backtrack();
            }

            s.pop_back();
            summ -= samp[i];
            used[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        samp = candidates;
        t = target;
        backtrack();

        for (int i = 0; i < index.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < index[i].size(); j++) {
                temp.push_back(samp[index[i][j]]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
