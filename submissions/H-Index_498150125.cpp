class Solution {
public:
    
    // Time : O(N * log N), Space : O(1)
    // N -> Size of citations list
    
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int low = 0, high = n - 1;
        int hIdx = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (n - mid <= citations[mid]) {
                hIdx = n - mid;
                high = mid - 1;
            } else
                low = mid + 1;                        
        }
        
        return hIdx;
    }
};