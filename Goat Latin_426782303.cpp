class Solution {
public:
    string toGoatLatin(string S) {
        int counter = 1;
        string ans = "";
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        for (int i = 0, j = 0; j < S.length(); ++j) {
            if (S[i] == ' ')
                break;
                
            while (j < S.length() && S[j] != ' ')
                j += 1;
            
            
            if (vowels.find(S[i]) != vowels.end()) {
                ans += S.substr(i, j - i) + "ma";
            } else {
                ans += S.substr(i + 1, j - i - 1) + S[i] + "ma";
            }
            
            for (int k = 0; k < counter; ++k)
                ans += "a";
            
            if (j != S.length())
                ans += " ";
            
            counter += 1;
            i = j + 1;
        }
        
        return ans;
    }
};
