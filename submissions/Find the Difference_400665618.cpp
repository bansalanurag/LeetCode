class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = ' ';
        vector<int> C(26, 0);
        for (char i : s) C[i - 'a'] += 1;
        for (char i : t) C[i - 'a'] -= 1;
        for (int i = 0; i < 26; ++i) {
            if (C[i] < 0) {
                ans = (char) (i + 'a');
            }
        }
        return ans;
    }
};
