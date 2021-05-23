class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;        
        for (int i = 0; i < s.length(); ++i) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            int len = max(len1, len2);
            if (end - start < len) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        
        return s.substr(start, end - start + 1);
    }
    
    int expand(string s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        
        return r - l - 1;
    }
};
