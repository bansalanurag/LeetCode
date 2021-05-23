class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if (trips.size() == 0) return true;
        int C[1005];
        memset(C, 0, sizeof(C));
        for (int i = 0; i < trips.size(); ++i) {
            C[trips[i][1]] += trips[i][0];
            C[trips[i][2]] -= trips[i][0];
        }
        int c = 0;
        for (int i = 0; i < 1005; ++i) {
            c += C[i];
            if (c > capacity) return false;
        }
        return true;
    }
};
