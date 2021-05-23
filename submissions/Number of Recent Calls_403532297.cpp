class RecentCounter {
public:
    
    vector<int> time;
    
    RecentCounter() {
        
    }
    
    int firstIndex(int x) {
        int n = time.size();
        int l = 0, h = n - 1;
        int ans = -1;
        while (l <= h) {
            int m = l + (h - l) / 2; 
            if (time[m]  >= x) {
                h = m - 1;
                ans = m - 1;
            } else 
                l = m + 1;
        }
        return ans;
    }   
    
    int ping(int t) {
        time.push_back(t);
        int low = firstIndex(t - 3000);
        int up = time.size() - 1;
        return (up - low);
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
