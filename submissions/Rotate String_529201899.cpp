class Solution {
public:
    
    vector<int> computeLSP(string pattern) {
        int m = pattern.length();
        int i = 1;
        int len = 0;
        vector<int> lps(m, 0);

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                lps[i] = len + 1;
                i += 1;
                len += 1;
            } else {
                if (len != 0)
                    len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i += 1;
                }
            }
        }

        return lps;
    }
    
    bool kmp(string text, string pattern) {
        vector<int> lsp = computeLSP(pattern);
        int i = 0;
        int j = 0;
        
        while (i < text.length()) {
            if (text[i] == pattern[j]) {
                i += 1;
                j += 1;
            } else {
                if (j != 0)
                    j = lsp[j - 1];
                else
                    i += 1;
            }
            
            if (j == pattern.length())
                return true;
        }
        
        return false;
    }
    
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        
        return kmp(s + s, goal);
    }
};