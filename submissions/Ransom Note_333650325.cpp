class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> V(26, 0);
        for (char i : ransomNote) V[i - 'a'] += 1;
        for (char i : magazine) if (V[i - 'a'] > 0) V[i - 'a'] -= 1;
        for (int i : V) if (i > 0) return false;
        return true;
    }
};
