class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {            
            ans += s[i] - 'A' + 1;
            if (i != s.length() - 1) {
                ans *= 26;
            }
        }
        return ans;
    }
};
