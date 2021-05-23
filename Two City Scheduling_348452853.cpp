class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int ans = 0;
        int n = costs.size();        
        sort(costs.begin() , costs.end() , [] (vector<int>& a,vector<int>& b) {
            return a[1]-a[0] > b[1]-b[0];        
        });        
        for(int i = 0 ; i < n; ++i) ans += (i < n / 2) ? costs[i][0] : costs[i][1];        
        
        return ans;
    }
};
