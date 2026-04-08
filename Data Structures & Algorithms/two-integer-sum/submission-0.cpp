class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> myMap;

        for (int i = 0; i < nums.size(); i++) {
            // if (myMap[nums[i]] == 0) {
                int c = target - nums[i];
                auto it = myMap.find(c);
                if (it != myMap.end()) {
                    vector<int> res(2);
                    res[0] = it->second;
                    res[1] = i;
                    return res;
                }
                myMap[nums[i]] = i;
            // }
        }

    }
};
