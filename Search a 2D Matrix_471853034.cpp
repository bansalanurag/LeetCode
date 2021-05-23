class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int l = 0, h = matrix.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (target >= matrix[m][0] && target <= matrix[m][matrix[m].size() - 1]) {
                row = m;
                break;
            } else if (target > matrix[m][0])
                l = m + 1;
            else 
                h = m - 1;
        }
        
        vector<int> toSearch = matrix[row];
        l = 0, h = toSearch.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (toSearch[m] == target)
                return true;
            else if (target < toSearch[m])
                h = m - 1;
            else
                l = m + 1;
        }
        
        return false;
    }
};
