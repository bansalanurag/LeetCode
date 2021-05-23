class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> M;
        int maxSize = 0;
        int minNum = INT_MAX;
        for (int i : nums) { M[i] += 1; maxSize = max(maxSize, M[i]); minNum = min(minNum, i);}
        vector<int> ans;
        
        if (maxSize == 1 && k == 1) {
            ans.push_back(minNum);
            return ans;
        }
        
        vector<vector<int>> V(maxSize + 1, vector<int> ());
        for (auto i : M) V[i.second].push_back(i.first); 
        for (int i = maxSize; i > 0 && k > 0; --i) {
            if (V[i].size() != 0) {
                for (int j : V[i]) {
                    ans.push_back(j);
                    k -= 1;
                    if (k <= 0) break;
                }
            }
        }
        return ans;
    }
};
