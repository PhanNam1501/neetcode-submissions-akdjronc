class Solution {
private:
    int left = 0;
    int right = 0;
    vector<string> sample;
    vector<string> res;
    string s;
    int N;
public:
    void backtrack() {
        if (left == N && right == N) {
            res.push_back(s);
            return;
        }
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                if (left == N) continue;
                s += sample[i];
                left++;
            } else {
                if (right == left) continue;
                s += sample[i];
                right++;
            }
            char c = s[s.size()-1];
            backtrack();
            if (c == '(') {
                left--;
            } else {
                right--;
            }
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        N = n;
        sample.push_back("(");
        sample.push_back(")");
        backtrack();
        return res;
    }
};
