class Solution {
public:
    int findMin(vector<int>& A) {
        int n = A.size();
        int l = 0, h = n - 1;
        while (l <= h) {
            if (A[l] <= A[h]) return A[l];
            
            int m = l + (h - l) / 2;
            int prev = (m + n - 1) % n;
            int next = (m + 1) % n;
            if (A[m] <= A[next] && A[m] <= A[prev]) return A[m];
            else if (A[m] <= A[h]) h = m - 1;
            else l = m + 1;
        }
        return -1;
    }
};
