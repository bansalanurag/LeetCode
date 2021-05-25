class Solution {
public:    
    
    // Time : O(N), Space : O(10 * N) ~ O(N)
    // N -> Length of the string
    
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        
        if (s.length() < 10)
            return ans;
        
        int i = 0, j = 9;
        unordered_set<string> ansSet;
        unordered_set<string> foundSequences;
        
        while (j < s.length()) {
            string winString = s.substr(i, j - i + 1);
            
            if (foundSequences.find(winString) != foundSequences.end()) {
                ansSet.insert(winString);
            } else {
                foundSequences.insert(winString);
            }
            
            i += 1;
            j += 1;
        }
        
        for (string sequence : ansSet) {
            ans.push_back(sequence);
        }
        
        return ans;
    }
};