class Solution {
public:    
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        for(int i = 2; i <= len; i++) {
            if(len%i == 0) {
                if(check(s, len/i)) return true;
            }
        }
        return false;
    }
    
    bool check(string s, int len) {
        int t = len, nxt = t + len, idx = 0;
        while(t < s.length()) {
            while(t < nxt) if(s[idx++] != s[t++]) return false;
            idx = 0;
            nxt = t + len;
        }
        return true;
    }
};
