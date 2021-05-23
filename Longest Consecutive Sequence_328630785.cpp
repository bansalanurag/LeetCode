class Solution {
public:
    int longestConsecutive(vector<int>& A) {
        if (A.size() == 0) return 0;
        int ans = 1, curr = 1;
        int prev = 0;
        set<int> S;         
        
        for (int i : A) S.insert(i);          
        bool count = true;
        for (int i : S) {
            if (count) {
                count = false;
                prev = i;
                continue;
            }
            
            if (i - 1 == prev) {
                curr += 1;
            } else {  
                ans = max(ans, curr); 
                curr = 1; 
            }            
            prev = i;
        }
        ans = max(ans, curr);
        return ans;
    }
};
