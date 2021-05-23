class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.length() != s.length()) return false;
        
        bool valid = true;
        vector<int> C(26, 0); 
        for (char i : s) C[i - 'a'] += 1;
        for (char i : t) {
            if (C[i - 'a']-- <= 0) {
                valid = false;
                break;
            }
        }
        return valid;
    }
};
