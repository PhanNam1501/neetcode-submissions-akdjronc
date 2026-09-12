class Solution {
private:
    int timespick = 0;
    int idxnow = 0;
    vector<pair<int, int>> w;
public:
    Solution(vector<int>& w) {
        for (int i = 0; i < w.size(); i++) {
            this->w.push_back(pair<int, double>{i, w[i]});
        }

        sort(this->w.begin(), this->w.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        this->timespick = this->w[this->w.size()-1].second;
        this->idxnow = this->w.size()-1;
    }
    
    int pickIndex() {
        int l = 0;
        int r = this->w.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (this->w[m].second <= this->w[this->idxnow].second-1) l = m + 1;
            else r = m;
        }

        this->timespick--;
        if (this->timespick == 0) {
            if (this->idxnow == 0) {
                this->idxnow = this->w.size()-1;
                this->timespick = this->w[this->w.size()-1].second;
            } else {
                this->idxnow--;
                this->timespick = this->w[this->idxnow].second;
            }
        }

        return this->w[l].first;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */