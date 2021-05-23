class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> Acount, Bcount;
        
        int maxCntInA = 0, maxInA = 0;
        int maxCntInB = 0, maxInB = 0;
        
        for (int i : A) {
            Acount[i] += 1;
            if (Acount[i] > maxCntInA) {
                maxCntInA = Acount[i];
                maxInA = i;
            }
        }
        for (int i : B) {
            Bcount[i] += 1;
            if (Bcount[i] > maxCntInB) {
                maxCntInB = Bcount[i];
                maxInB = i;
            }
        }
        
        if (maxCntInA > maxCntInB) {
            int swapCnt = 0;
            for (int i = 0; i < A.size(); ++i) {
                if (A[i] != maxInA) {
                    if (B[i] == maxInA)
                        swapCnt += 1;
                    else
                        return -1;
                }
            }
            
            if (swapCnt + maxCntInA == A.size())
                return swapCnt;
        } else {
            int swapCnt = 0;
            for (int i = 0; i < B.size(); ++i) {
                if (B[i] != maxInB) {
                    if (A[i] == maxInB)
                        swapCnt += 1;
                    else
                        return -1;
                }
            }
            
            if (swapCnt + maxCntInB == B.size())
                return swapCnt;            
        }        
        
        return -1;
    }
};


/*

Count -> val
A : {2 - 3, 1 - 1, 1 - 2, 1 - 5}
B : {3 - 3, 1 - 6, 1 - 4}

*/
