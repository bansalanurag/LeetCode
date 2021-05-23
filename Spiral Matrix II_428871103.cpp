class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n));
        
        int dir = 0;
        int counter = 1;
        int l = 0, r = n - 1, u = 0, d = n - 1;
        while (l <= r && u <= d) {
            if (dir == 0) {
                for (int i = l; i <= r; ++i)
                    ans[u][i] = counter++;
                u += 1;
            } else if (dir == 1) {
                for (int i = u; i <= d; ++i)
                    ans[i][r] = counter++;
                r -= 1;
            } else if (dir == 2) {
                for (int i = r; i >= l; --i)
                    ans[d][i] = counter++;
                d -= 1;
            } else {
                for (int i = d; i >= u; --i)
                    ans[i][l] = counter++;
                l += 1;
            }
            dir = (dir + 1) % 4;
        }
        
        return ans;
    }
};
