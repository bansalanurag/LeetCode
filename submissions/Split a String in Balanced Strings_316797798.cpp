class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int c1, c2;
        c1 = c2 = 0;
        for (char c : s) {
            c == 'R'? c1 += 1 : c2 += 1;
            if (c1 == c2) ans += 1;
        }
        return ans;
    }
};
