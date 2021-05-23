class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        if (intervals.size() == 0 && newInterval.size() == 0)   return result;
        if (intervals.size() != 0 && newInterval.size() == 0)    return intervals;
        if (intervals.size() == 0 && newInterval.size() != 0) {
            result.emplace_back(newInterval);
            return result;
        }
        
        intervals.emplace_back(newInterval);
        vector<pair<int, int>> I(intervals.size());
        for (int i = 0; i < intervals.size(); ++i)
            I[i] = make_pair(intervals[i][0], intervals[i][1]);
        sort(I.begin(), I.end());
        for (int i = 0; i < I.size(); ++i) {
            int start = I[i].first;
            int end = I[i].second;
            while (i < I.size() - 1 && end >= I[i + 1].first) {
                i += 1;
                end = max(end, I[i].second);                
            }
            vector<int> temp{start, end};
            result.emplace_back(temp);
        }
        return result;
    }
};
