class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i, j, k;
        i = j = k = 0;
        vector<int> C(m + n, 0);
        
        while (i < m && j < n) {
            if (A[i] < B[j]) {
                C[k++] = A[i++];
            } else if (A[i] > B[j]) {
                C[k++] = B[j++];
            } else {
                C[k++] = A[i++];
                C[k++] = B[j++];
            }
        }
        
        while (i < m) C[k++] = A[i++];
        while (j < n) C[k++] = B[j++];
        for (i = 0; i < m + n; ++i) A[i] = C[i];
        
    }
};
