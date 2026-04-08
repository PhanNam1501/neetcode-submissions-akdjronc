class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> m;
        for (int i = 0; i < nums.size(); i++) {
            auto it = m.find(nums[i]);
            if (it != m.end()) {
                return true;
            } else {
                m.insert(nums[i]);
            }
        }

        return false;
    }
};