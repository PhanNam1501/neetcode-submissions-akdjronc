class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> myMap;
        for (int i = 0; i < n; i++) {
            myMap[nums[i]] += 1;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            auto it = myMap.find(i+1);
            if (it == myMap.end()) {
                res.push_back(i+1);
            }
        }

        return res;
    }
};