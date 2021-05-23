class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() == 0)  return true;
        bool valid1 = true, valid2 = true;
        for (int i = 0 ; i < A.size() - 1; ++i) {
            if (A[i + 1] < A[i]) {
                valid1 = false;
                break;
            }
        }
        for (int i = 0 ; i < A.size() - 1; ++i) {
            if (A[i + 1] > A[i]) {
                valid2 = false;
                break;
            }
        }
        return (valid1 || valid2);
    }
};
