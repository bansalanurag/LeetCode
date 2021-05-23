class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if (words.empty()) return 0;
        
        vector<string> codes{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","
            ---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
        unordered_set<string> S;
        for (string word : words) {
            string code = "";
            for (char i : word) {
                code += codes[i - 'a'];
            }
            S.insert(code);
        }

        return S.size();
    }
};
