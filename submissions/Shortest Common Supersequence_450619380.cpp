class Solution {
public:
    
    string LCS(string X, string Y) {
        int n = X.length();
        int m = Y.length();
        
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                    continue;                    
                }
                
                if (X[i - 1] == Y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        string lcs = "";
        int i = n, j = m; 
        while (i > 0 && j > 0) {
            if (X[i - 1] == Y[j - 1]) {
                lcs += X[i - 1];
                i -= 1;
                j -= 1;                
            } else {
                if (dp[i - 1][j] > dp[i][j - 1])
                    i -= 1;
                else
                    j -= 1;
            }
        }
        
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
    
    string shortestCommonSupersequence(string A, string B) {
        string lcs = LCS(A, B);
        string ans = "";
        
        int i = 0, j = 0, k = 0;
        while (i < A.length() && j < B.length()) {
            if (A[i] == B[j] && lcs[k] == A[i]) {
                ans += lcs[k++];
                i++;
                j++;
            } else {
                if (A[i] == lcs[k]) {
                    ans += B[j++];
                } else if (B[j] == lcs[k])
                    ans += A[i++];
                else {
                    ans += A[i++];
                    ans += B[j++];
                }
            }
        }
        
        while (i < A.length()) ans += A[i++];
        while (j < B.length()) ans += B[j++];
        
        return ans;
    }
};
