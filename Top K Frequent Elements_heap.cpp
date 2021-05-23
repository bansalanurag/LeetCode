class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> M;
        priority_queue<pair<int, int>> Q;
        
        for (int i : nums) 
            M[i] += 1;
        
        for (auto i : M) 
            Q.push({i.second, i.first});
        
        while (k-- > 0) {
            ans.push_back(Q.top().second);
            Q.pop();
        }
        
        return ans;
    }
};
