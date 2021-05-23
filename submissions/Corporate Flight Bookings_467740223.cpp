class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for (auto V : bookings) {
            ans[V[0] - 1] += V[2];
            if (V[1] < n)
                ans[V[1]] -= V[2];
        }
        
        int cum = 0;
        vector<int> result(n, 0);
        for (int i = 0; i < n; ++i) {
            cum += ans[i];
            result[i] = cum;            
        }
        
        return result;
    }
};
