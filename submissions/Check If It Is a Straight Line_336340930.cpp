class Solution {
public:
    int cross(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
        vector<int> ab{b[0] - a[0], b[1] - a[1]};
        vector<int> ac{c[0] - a[0], c[1] - a[1]};
        return ab[0] * ac[1] - ab[1] * ac[0];
    }
    
    bool checkStraightLine(vector<vector<int>>& A) {
        if (A.size() <= 2) return true;
        
        for (int i = 0; i < A.size() - 2; ++i) {
            if (cross(A[i], A[i + 1], A[i + 2]) != 0)
                return false;
        }        
        return true;
    }
};

