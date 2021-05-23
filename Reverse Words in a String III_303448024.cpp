class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n;) {
            int j = i + 1;
            for (; s[j] != ' ' && j < n ; ++j);
            string temp = s.substr(i, j - i);
            reverse(temp.begin(), temp.end());
            ans += temp + " "; 
            i = j + 1;
        }
        return ans.substr(0, ans.length() - 1);
    }
};
