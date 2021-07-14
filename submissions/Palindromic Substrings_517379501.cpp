class Solution {
public:
    
    int computePalinedrome(string &s, int l, int r) {
        int cnt = 0;
        while (l >= 0 && r <= s.length() && s[l] == s[r]) {
            cnt += 1;
            l -= 1;
            r += 1;
        }
        return cnt;
    }
    
    int countSubstrings(string s) {
        int numOfSubstring = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            numOfSubstring += computePalinedrome(s, i, i);
            numOfSubstring += computePalinedrome(s, i, i + 1);        
        }
        
        return numOfSubstring;
    }
};