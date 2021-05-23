class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        int C[52];
        memset(C, 0, sizeof(C));
        for (char i : s) {
            if ((int) i >= 97 && (int) i <= 122)
                C[i - 'a'] += 1;
            else
                C[i - 'A' + 26] += 1;
        }
        for (int i = 0; i < 52; ++i) {
            if (C[i]&1) {
                if (C[i] > 1) {
                    ans += C[i] - 1;
                    C[i] = 1;
                }                
            } else {
                ans += C[i];
                C[i] = 0;
            }
        }
        for (int i = 0; i < 52; ++i) {
            if (C[i] == 1) { 
                ans += 1;
                break; 
            }
        }
        return ans;
    }
};
