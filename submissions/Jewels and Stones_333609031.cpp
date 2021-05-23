class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans = 0;
        vector<int> Jewels(52, 0);
        vector<int> Stones(52, 0);
        for (char i : J) i < 'a' ? Jewels[i - 'A'] += 1 : Jewels[i - 'a' + 26] += 1;
        for (char i : S) i < 'a' ? Stones[i - 'A'] += 1 : Stones[i - 'a' + 26] += 1;
        for (int i = 0; i < 52; ++i) if (Jewels[i] > 0 && Stones[i] > 0) ans += Stones[i];
        return ans;
    }
};
