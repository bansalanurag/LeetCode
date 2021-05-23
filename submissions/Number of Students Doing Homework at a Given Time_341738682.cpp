class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
            
        int ans = 0;
        int n = startTime.size();
        for (int i = 0; i < n; ++i) {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime)
                ans += 1;
        }
        return ans;
    }
};
