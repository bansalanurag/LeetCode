class Solution {
public:
    
    vector<int> color;
    vector<bool> visited;
    vector<vector<int>> A;
    
    bool bipartite(int v, int col) {
        color[v] = col;
        visited[v] = true;        
        for (int u : A[v]) {
            if (!visited[u])
                bipartite(u, col ^ 1);
            else if (color[u] == col)
                return false;
        }        
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        if (edges.empty() || n <= 2) return true;
        
        color.resize(n, -1);
        visited.resize(n, false);
        A.resize(n, vector<int> ());        
        
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            A[u].push_back(v);
            A[v].push_back(u);
        }
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (!bipartite(i, 1))
                    return false;
            }
        }
        
        return true;
    }
};
