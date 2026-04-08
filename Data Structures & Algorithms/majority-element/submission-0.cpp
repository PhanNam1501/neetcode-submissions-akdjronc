class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> myMap;
        int n = nums.size() / 2;
        for (int i = 0; i < nums.size(); i++) {
            myMap[nums[i]]++;
            if (myMap[nums[i]] > n) {
                return nums[i];
            }
        }
    }
};