class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) return false;
        if (A == B && set<char>(A.begin(), A.end()).size() < A.size()) return true;

        int a = -1, b = -1;
        for (int i = 0; i < A.length(); ++i) {
            if (A[i] != B[i]) {
                if (a == -1) {
                    a = i;
                } else if (b == -1) {
                    b = i;
                } else
                    return false;                    
            }
        }

        if (a == -1 || b == -1 || A[a] != B[b] || A[b] != B[a])
            return false;

        return true;
    }
};
