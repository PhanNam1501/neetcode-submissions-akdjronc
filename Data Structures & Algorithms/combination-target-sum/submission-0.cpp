class Solution {
private: 
    vector<vector<int>> indexs;
    vector<vector<int>> res;
    vector<int> neet;
    vector<int> s;
    unordered_map<int, bool> used;
    int summ = 0;
    int t;
public:
    void backtrack() {
        int lastIndex = s.empty() ? 0 : s.back();
        for (int i = lastIndex; i < neet.size(); i++) {
            s.push_back(i);
            summ += neet[i];
            
            if(summ >= t) {
                if (summ == t) {
                    indexs.push_back(s);
                }
            } else {
                backtrack();
            }
            s.pop_back();
            summ -= neet[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        t = target;
        neet = nums;
        backtrack();
        for (int i = 0; i < indexs.size(); i++) {
            vector<int> temp;
            for (int j = 0; j < indexs[i].size(); j++) {
                temp.push_back(nums[indexs[i][j]]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
