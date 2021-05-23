class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freqMapT;
        for (char letter : t) {
            freqMapT[letter] += 1;
        }
        
        int distinctCount = freqMapT.size();
        int left = 0, right = 0;
        
        int minWindowLen = s.length() + 1;
        string minWindowString = "";
        
        while (right < s.length()) {
            freqMapT[s[right]] -= 1;
            if (freqMapT[s[right]] == 0) 
                distinctCount -= 1;
            
            if (distinctCount > 0) {
                right += 1;
                continue;
            }
            
            while (distinctCount < 1) {
                if (minWindowLen > right - left + 1) {
                    minWindowString = s.substr(left, right - left + 1);
                    minWindowLen = minWindowString.length();
                }        
                
                freqMapT[s[left]] += 1;
                if (freqMapT[s[left]] == 1)
                    distinctCount += 1;
                
                left += 1;
            }
            
            right += 1;
        }
        
        return minWindowString;
    }
};
