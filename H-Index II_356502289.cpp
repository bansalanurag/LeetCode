class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        int n = citations.size();
        int l = 0, h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (citations[m] >= n - m) {
                ans = n - m;
                h = m - 1;
            } else
                l = m + 1;            
        }
        return ans; 
    }
};
