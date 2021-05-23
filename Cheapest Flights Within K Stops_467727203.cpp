class Solution {
public:
    
    int ans = INT_MAX;
    
    void dfs(vector<vector<pair<int, int>>> &G, int s, int d, int k, vector<bool> &visited, int cost) {
        if (k < -1)
            return;
        
        if (cost >= ans)
            return;
        
        if (s == d) {
            ans = min(ans, cost);
            return;
        }
        
        visited[s] = true;
        for (pair<int, int> p : G[s]) {
            if (!visited[p.first])
                dfs(G, p.first, d, k - 1, visited, cost + p.second);
        }
        visited[s] = false;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> G(n, vector<pair<int, int>> ());
        vector<bool> visited(n, false);
        
        for (auto i : flights) 
            G[i[0]].push_back({i[1], i[2]});
        
        dfs(G, src, dst, K, visited, 0);
        
        return (ans == INT_MAX ? -1 : ans);
    }
};
