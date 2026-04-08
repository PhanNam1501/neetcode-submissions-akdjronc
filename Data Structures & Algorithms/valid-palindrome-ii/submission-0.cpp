class Solution {
public:
    bool validPalindrome(string s) {
        int del = 0;
        int l = 0;
        int r = s.size()-1;
        while(l < r) {
            while (s[l] != s[r]) {
                return isPalindrome(s, l+1, r) || isPalindrome(s, l, r-1);
            }
            l++;
            r--;
        }

        return true;
    }

    bool isPalindrome(string s, int l, int r) {
        while(l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};