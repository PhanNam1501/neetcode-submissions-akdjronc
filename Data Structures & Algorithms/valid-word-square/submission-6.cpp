class Solution {
public:
    bool validWordSquare(vector<string>& words) {
   

        for (int i = 0; i < words.size(); i++) {
            string li = words[i];
            string ri = "";
            int n = li.size();
            if (n > words.size()) return false;
            for (int j = 0; j < words.size(); j++) {
                int c = (int)words[j].size();
                if(c < (i + 1)) continue;
                ri.push_back(words[j][i]);
            }

            if (li != ri) {
                return false;
            }
        }

        return true;
    }
};
