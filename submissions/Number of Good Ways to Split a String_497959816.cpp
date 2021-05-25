class Solution {
public:
    
    // Time : O(N), Space : O(26) ~ O(1) [26 characters stored max in the maps]
    // N -> Length of the string
    
    bool areEqual(unordered_map<char, int> &A, unordered_map<char, int> &B) {
        return (A.size() == B.size());
    }
    
    int numSplits(string s) {
        int goodSplits = 0;
                
        if (s.length() <= 1) {
            return goodSplits;
        }
                    
        unordered_map<char, int> p, q;        
        
        // Preprocessing for Ist partition
        p[s[0]] += 1;        
        int j = 1;
        while (j < s.length()) {
            q[s[j]] += 1;            
            j += 1;
        }        
        if (areEqual(p, q)) goodSplits += 1;
        
        j = 2;
        while (j < s.length()) {
            p[s[j - 1]] += 1;
            q[s[j - 1]] -= 1;
            if (q[s[j - 1]] <= 0)
                q.erase(s[j - 1]);
            
            if (areEqual(p, q)) 
                goodSplits += 1;
            
            j += 1;
        }
        
        return goodSplits;    
    }
};