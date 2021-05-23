class Solution {
public:
    
    void merge(vector<int> &A, int p, int q, int r) {
        int i = p;
        int j = q + 1;
        vector<int> C;
        
        while (i <= q && j <= r) {
            if (A[i] <= A[j]) {
                C.emplace_back(A[i++]);
            } else
                C.emplace_back(A[j++]);
        }
        while (i <= q) C.emplace_back(A[i++]);
        while (j <= r) C.emplace_back(A[j++]);
        
        i = 0;
        for (int k = p; k <= r; ++k) {
            A[k] = C[i++];
        }        
    }        
    
    void mergeSort(vector<int> &A, int p, int r) {
        if (p < r) {
            int q = p + (r - p) / 2;
            mergeSort(A, p, q);
            mergeSort(A, q + 1, r);
            merge(A, p, q, r);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
