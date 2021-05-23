class Solution {
public:
    int ans = -1;
    vector<int> dp;
    
    int dfs(vector<vector<int>> &Adj, int v) {
        if (dp[v] > 0)
            return dp[v];
        
        dp[v] = 1;
        for (int i : Adj[v]) {
            dp[v] = max(dp[v], 1 + dfs(Adj, i));                
        }        
        
        return dp[v];
    }
    
    int longestStrChain(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        if (words.empty()) return 0;
                
        int n = 0;
        unordered_map<string, int> indexing;
        for (string s : words)
            indexing[s] = n++;
        
        dp.resize(n, 0);
        vector<int> parents(n, -1);        
        vector<vector<int>> Adj(n, vector<int> ());
        for (string s : words) {
            for (int j = 0; j < s.length(); ++j) {
                string match = s.substr(0, j) + s.substr(j + 1);
                if (indexing.find(match) == indexing.end())
                    continue;
                
                Adj[indexing[s]].push_back(indexing[match]);
                parents[indexing[match]] = indexing[s];
            }
        }
        
        for (int i = 0; i < parents.size(); ++i) {
            if (parents[i] == -1)
                ans = max(ans, dfs(Adj, i));
        }       
        
        return ans;
    }
};
