class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res(arr.size());
        int maxx = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            res[i] = maxx;
            maxx = max(maxx, arr[i]);
        }
        return res;
    }
}; 