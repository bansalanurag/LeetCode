class Solution {
public:
    
    bool areEqual(vector<int> &A, vector<int> &B) {
        for (int i = 0; i < 26; ++i)
            if (A[i] != B[i])
                return false;
        return true;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<int, vector<int>>> freq;
        vector<vector<string>> Anagrams;
        int k = 0;
        
        for (string word : strs) {
            vector<int> subfreq(26, 0);
            for (char i : word)
                subfreq[i - 'a'] += 1;
            
            bool found = false;
            for (int i = 0; i < freq.size(); ++i) {
                if (areEqual(subfreq, freq[i].second)) {
                    Anagrams[freq[i].first].push_back(word);
                    found = true;
                }
            }
                    
            if (!found) {
                freq.push_back({k, subfreq});
                vector<string> temp{word};
                Anagrams.push_back(temp);
                k += 1;
            }
        }
        
        return Anagrams;
    }
};
