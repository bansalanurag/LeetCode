class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> result;
        if (A.size() == 0)  return result;
        
        for (int i = 0; i < A.size(); ++i) {
            vector<int> temp;
            for (int j = A[i].size() - 1; j >= 0; --j)
                A[i][j] ? temp.push_back(0) : temp.push_back(1);
            result.push_back(temp);
        }
        return result;
    }
};
