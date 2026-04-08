class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxx = 0;
        for (int i = 1; i < arrays.size(); i++) {
            int m = max(abs(arrays[i][0] - arrays[i-1][arrays[i-1].size() - 1]), abs(arrays[i][arrays[i].size() - 1] - arrays[i-1][0]));
            maxx = max(maxx, m);
        }

        return maxx;
    }
};
