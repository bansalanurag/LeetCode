class Solution {
public:
    
    bool areConvertible(string A, string B) {
        if (A.length() != B.length())
            return false;

        unordered_map<char, char> forward, backward;
        for (int i = 0; i < A.length(); ++i) {
            if (forward.find(A[i]) == forward.end())
                forward[A[i]] = B[i];
            if (backward.find(B[i]) == backward.end())
                backward[B[i]] = A[i];
            
            if (forward[A[i]] != B[i] || backward[B[i]] != A[i])
                    return false;            
        }

        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for (string word : words) {
            if (areConvertible(word, pattern))
                ans.push_back(word);
        }

        return ans;
    }
};
