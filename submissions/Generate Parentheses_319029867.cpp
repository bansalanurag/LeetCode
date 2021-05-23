class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) return ans;
        if (n == 1) { ans.push_back("()"); return ans; }
        string curr = "(";
        generate(curr, n - 1, n, ans);
        return ans;
    }
    
    void generate(string curr, int openCount, int closeCount, vector<string> &ans) {
        if (openCount == 0 && closeCount == 0) {
            ans.push_back(curr);
            return;
        }
        if (openCount < 0 && closeCount != 0 || openCount != 0 && closeCount < 0 || closeCount < openCount) {
            return;        
        }
        
        generate(curr + "(", openCount - 1, closeCount, ans);
        generate(curr + ")", openCount, closeCount - 1, ans);        
    }
};
