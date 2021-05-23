class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int ans = INT_MAX;
        int n = wall.size();
        unordered_map<int, int> pos;
        
        int mx = 0, key;
        
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; ++j) {
                sum += wall[i][j];
                pos[sum] += 1;
                if (pos[sum] > mx) {
                    mx = pos[sum];
                    key = sum;
                }
            }
        }
        
        // for (auto i : pos) cout << i.first << " -> " << i.second << "\n";
        // cout << mx << " " << key;
        
        return mx == 0 ? n : n - mx;
    }
};
