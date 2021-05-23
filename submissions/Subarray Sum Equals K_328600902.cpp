class Solution {
public:
    int subarraySum(vector<int>& A, int k) {
        int ans = 0;
        if (A.empty()) return ans;
        
        int n = A.size();
        int curr = 0;
        map<long, int> C;
                
        for (int i = 0; i < n; ++i) {
            curr += A[i];
            if (curr == k) ans += 1;
            if (C.find(curr - k) != C.end())
                ans += C[curr - k];
            C[curr] += 1;
        }
        
        return ans;
    }
};
