class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> p;
        unordered_map<int, int> myMap;

        for (int i = 0; i < nums.size(); i++) {
            myMap[nums[i]]++;
        }

        for (auto m: myMap) {
            pair<int, int> t = {m.first, m.second};
            p.push_back(t);
        }

        sort(p.begin(), p.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(p[p.size() - i - 1].first);
        }

        return res;
    }
};
