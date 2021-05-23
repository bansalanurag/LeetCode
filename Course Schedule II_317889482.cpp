class Solution {
public:
        
    bool cycle = false;
    vector<int> visited;
    vector<vector<int>> A;
    
    void dfs(int v, vector<int> &ans) {
        visited[v] = 1;
        for (int u : A[v]) {
            if (visited[u] == 0) {
                dfs(u, ans);
            } else if (visited[u] == 1) {
                cycle = true;
                return;
            }
        }
        visited[v] = 2;
        ans.emplace_back(v);
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& G) {
        vector<int> ans;        
        visited.resize(n, 0);
        A.resize(n, vector<int> ());        
        for (auto i : G) A[i[1]].emplace_back(i[0]);
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0)
                dfs(i, ans);        
        }
        if (cycle) return (vector<int> ());
        reverse(ans.begin(), ans.end());        
        return ans;
    }
};
