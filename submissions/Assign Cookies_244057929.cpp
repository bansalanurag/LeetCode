class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.size() == 0 || s.size() == 0) return 0;
                
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        vector<bool> sold (s.size(), false); 
        int ans = 0;
        for (int i = 0; i < g.size(); ++i) {
            auto j = lower_bound(s.begin(), s.end(), g[i]);
            while (j != s.end() && sold[j - s.begin()]) ++j; 
            if (j != s.end()) {
                ans += 1;
                sold[j - s.begin()] = true;
            }
        }
        return ans;
    }
};
