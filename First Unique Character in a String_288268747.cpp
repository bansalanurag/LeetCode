class Solution {
public:
    int firstUniqChar(string s) {
        int count = 1;
        vector<int> C(26, 0), I(26, -1);
        for (int i = 0; i < s.length(); ++i) {
            int idx = s[i] - 'a';
            if (C[idx] == 0) { C[idx] = count++; I[idx] = i; } 
            else C[idx] = -1;            
        }
        int idx = -1, check = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (C[i] > 0 && C[i] < check) {
                check = C[i];
                idx = i;
            }  
        }         
        return (idx == -1 ? -1 : I[idx]);
    }
};
