class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxx = arrays[0][arrays[0].size()-1];
        int minn = arrays[0][0];
        int res = 0;
       
        for (int i = 1; i < arrays.size(); i++) {
            vector<int> t = arrays[i];

            int c = max(abs(t[t.size() - 1] - minn), abs(t[0] - maxx));
            res = max(res, c);
            maxx = max(maxx, t[t.size() - 1]);
            minn = min(minn, t[0]);
        }
        return res;
    }
};
