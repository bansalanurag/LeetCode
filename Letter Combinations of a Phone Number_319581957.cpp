class Solution {
public:
    
    vector<string> mapping {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;       
        if (digits.empty()) return ans;
        int idx = 0;
        for (char c : mapping[digits[idx] - '0']) {
            string word = "";
            generate(digits, word + c, idx + 1, ans);
        }
        return ans;
    }
    
    void generate(string digits, string word, int idx, vector<string> &ans) {
        if (idx >= digits.length()) {
            ans.push_back(word);
            return;
        }
        for (char c : mapping[digits[idx] - '0']) {
            generate(digits, word + c, idx + 1, ans);
        }
    }    
};
