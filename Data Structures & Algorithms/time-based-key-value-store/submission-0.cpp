class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> timemp;
public:
    TimeMap() {
        
    }

    int binarysearch(vector<pair<string,int>> &arr, int timestamp) {
        int l = -1;
        int r = arr.size();

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (arr[m].second > timestamp) r = m;
            else l = m;
        }

        return l;
    }
    
    void set(string key, string value, int timestamp) {
        this->timemp[key].push_back(pair<string, int>{value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int t = binarysearch(this->timemp[key], timestamp);
        if (t == -1) return "";
        return this->timemp[key][t].first;
    }
};

// key -> pair{value, timestamp}
