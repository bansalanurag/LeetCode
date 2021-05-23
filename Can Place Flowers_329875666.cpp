class Solution {
public:
    bool canPlaceFlowers(vector<int>& A, int n) {
        if (A.empty()) return false;
        if (n == 0 || (A.size() == 1 && A[0] == 0)) return true;
        
        if (A[0] == 0 && A[1] != 1) {
            A[0] = 1; 
            n--;
        }
        for (int i = 1; i < A.size() - 1; ++i) {
            if (A[i] != 1) {
                if (A[i - 1] == 1 || A[i + 1] == 1)
                    continue;
                A[i] = 1;
                n--;
            }
        }
        if (n > 0 && A[A.size() - 1] == 0 && A[A.size() - 2] != 1) {
            A[A.size() - 1] = 1; 
            n--;
        }
        
        return n <= 0;
    }
};
