class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        
        map<char,char> A;
        unordered_set<char> taken;
        for (int i = 0; i < s.length(); ++i) {
            if (A.find(s[i]) == A.end()) {
                if (taken.find(t[i]) == taken.end()) {
                    taken.insert(t[i]);  
                    A[s[i]] = t[i];
                } else 
                    return false;
            } else {
                if (A[s[i]] != t[i])
                    return false;
            }
        }
        
        return true;
    }
};
