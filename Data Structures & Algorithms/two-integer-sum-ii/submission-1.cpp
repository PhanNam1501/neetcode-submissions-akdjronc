class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> m;
        vector<int> res(2);
        for (int i = 0; i < numbers.size(); i++) {
            // if (numbers[i] >= target) {
            //     break;
            // }

            auto it = m.find(numbers[i]);
            if (it != m.end()) {
                res[0] = it->second;
                res[1] = i + 1;
                break;
            }

            int k = target - numbers[i];
            m[k] = i + 1;
        }

        return res;
    }
};
