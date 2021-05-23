class Solution {
public:
    string customSortString(string S, string T) {
        string ans = "";
        unordered_set<char> C; 
        unordered_map<char, int> B;
        for (char i : S) C.insert(i);
        for (char i : T) B[i] += 1;
        for (int i = 0; i < S.length(); ++i) {
            if (B.find(S[i]) != B.end()) {
                while (B[S[i]]-- > 0)
                    ans += S[i];
            }
        }
        for (int i = 0; i < T.length(); ++i) {
            if (C.find(T[i]) == C.end())
                ans += T[i];
        }
        return ans;
        
    }
};
