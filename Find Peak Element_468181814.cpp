class Solution {
public:
    int findPeakElement(vector<int>& A) {
        int l = 0, h = A.size() - 1;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (A[m + 1] < A[m])
                h = m;
            else
                l = m + 1;
        }
        return l;
    }
};
