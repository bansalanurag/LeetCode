class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0) return true;
        if (s.length() > t.length()) return false;
        bool valid = true;
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            while (j < t.length() && s[i] != t[j]) j++;
            if (i != s.length() && j == t.length()) valid = false;
            i++; j++;
        }
        if (i != s.length()) valid = false;
        return valid;
    }
};
