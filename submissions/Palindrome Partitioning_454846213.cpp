class Solution {
public:
    
    bool isPalindrome(string s, int i, int j) {
        while (i <= j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    
    void solve(string s, vector<string> &temp, vector<vector<string>> &ans, int i, int j) {
        if (i >= s.length())
            ans.push_back(temp);
        
        for (int k = i; k <= j; ++k) {
            if (isPalindrome(s, i, k)) {
                temp.push_back(s.substr(i, k - i + 1));
                solve(s, temp, ans, k + 1, j);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, temp, ans, 0, s.length() - 1);
        return ans;
    }
};
