class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int, int> myMap;
        for (int i = 0; i < arr.size(); i++) {
            myMap[arr[i]] += 1;
        }
        int maxx = -1;
        for (auto m: myMap) {
            if (m.second == m.first) {
                maxx = max(maxx, m.first);
            }
        }
        return maxx;
    }
};