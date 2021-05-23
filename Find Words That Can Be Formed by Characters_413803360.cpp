class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        vector<int> C1(26, 0);
        for (char c : chars) C1[c - 'a'] += 1;
        for (string word : words) {
            vector<int> C2 = C1;
            bool possible = true;
            for (char c : word) {
                if (C1[c - 'a'] <= 0) {
                    possible = false;
                    break;
                } else {
                    C1[c - 'a'] -= 1;
                }
            }
            if (possible) ans += word.length();
            C1 = C2;
        }
        return ans;
    }
};
