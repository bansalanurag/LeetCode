class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        int n = points.size();
        vector<vector<int>> ans;
        multiset<pair<float, pair<int, int>>> S;
        for (int i = 0; i < n; ++i) {
            int x = points[i][0];
            int y = points[i][1];
            S.insert({sqrt(x * x + y * y), {x, y}});
        }
        for (auto i = S.begin(); i != S.end() && k-- > 0; ++i)
            ans.push_back(vector<int> {i->second.first, i->second.second});
        
        return ans;
    }
};
