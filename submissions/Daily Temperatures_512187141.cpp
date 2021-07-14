class Solution {
public:
    
    // Next Greater Element on Right Side.
    // Time : O(N) ; Space : O(N)
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> days(temperatures.size(), 0);
        stack<pair<int, int>> S;
        
        int i = temperatures.size() - 1;
        while (i >= 0) {
            if (S.empty()) {
                S.push({temperatures[i], i});
                days[i--] = 0;
                continue;
            }
            
            while (!S.empty() && S.top().first <= temperatures[i]) {
                S.pop();
            }            
            days[i] = !S.empty() ? S.top().second - i : 0;
            
            S.push({temperatures[i], i});
            i -= 1;
        }
        
        return days;
    }
};