class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        if (A.empty() || B.empty())
            return ans;
        
        int i = 0;
        int j = 0;
        while (i < A.size() && j < B.size()) {
            int a = A[i][0], b = A[i][1];
            int c = B[j][0], d = B[j][1];
            
            if (a > d || c > b) {
                if (b < d) 
                    i++;
                else 
                    j++;                
                continue;
            }
            
            int start = max(a, c);
            int end = min(b, d);
            ans.emplace_back(vector<int> {start, end});
            
            if (b < d) 
                i++;
            else if (b > d) 
                j++;
            else {
                i++;
                j++;
            }   
        }
        
        return ans;
    }
};
