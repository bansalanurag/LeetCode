class Solution {
public:
    
    bool areEqual(unordered_map<char, int> &A, unordered_map<char, int> &B) {
        for (auto i : A) {
            if (B.find(i.first) == B.end() || B[i.first] != i.second)
                return false;            
        }
        return true;
    }
    
    vector<int> findAnagrams(string target, string pattern) {        
        vector<int> ans;
    
        int pCounter = 0;
        unordered_map<char, int> patternFreq, targetFreq;
        for (char i : pattern) {
            patternFreq[i] += 1;            
            pCounter += 1;
        }
        
        int tCounter = 0;
        for (int i = 0; i < pattern.length(); ++i) {
            if (patternFreq.find(target[i]) != patternFreq.end()) {
                targetFreq[target[i]] += 1;
                tCounter += 1;
            }
        } 
        // if (pCounter == tCounter)
        //     ans.push_back(0);
        if (areEqual(patternFreq, targetFreq))
            ans.push_back(0);
        
        for (int i = pattern.length(); i < target.length(); ++i) {
            if (patternFreq.find(target[i]) != patternFreq.end()) {
                targetFreq[target[i]] += 1;
                tCounter += 1;                
            }
            
            if (targetFreq.find(target[i - pattern.length()]) != targetFreq.end()) {
                targetFreq[target[i - pattern.length()]] -= 1;
                tCounter -= 1;   
            }
            
            if (areEqual(patternFreq, targetFreq))
                ans.push_back(i - pattern.length() + 1);
        }
        
        return ans;
    }
};


// Complexity -> O(N * K)
