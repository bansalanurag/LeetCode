class Solution {
public:
    bool canJump(vector<int>& A) {
        int lastPos = A.size() - 1;
        for (int i = A.size() - 1; i >= 0; i--) {
            if (i + A[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
};
