class Solution {
public:
    // Time : O(N), Space : O(1)
    // N -> Length of the string
    
    string getHint(string secret, string guess) {
        unordered_map<char, int> freqA, freqB;
        
        for (char c : secret) freqA[c] += 1;
        for (char c : guess) freqB[c] += 1;        
        
        int cow = 0, bull = 0;
        for (int i = 0; i < guess.length(); ++i) {
            if (guess[i] == secret[i]) {
                bull += 1;
                freqA[guess[i]] -= 1;
                freqB[guess[i]] -= 1;
            }  
        }
        for (int i = 0; i < guess.length(); ++i) {
            if (guess[i] != secret[i]) {
                if (freqB.find(secret[i]) != freqB.end() && freqB[secret[i]] > 0) {
                    cow += 1;
                    freqB[secret[i]] -= 1;
                }
            }
        }
        
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};