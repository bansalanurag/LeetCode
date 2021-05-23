class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        for (int i = 0; i < (1 << n); ++i) {
            vector<int> subset;
            for (int j = 0; j < n; ++j) {
                if ((1 << j) & i)
                    subset.push_back(j + 1);
            }
            if (subset.size() == k)
                ans.push_back(subset);
        }
        
        return ans;
    }
};
