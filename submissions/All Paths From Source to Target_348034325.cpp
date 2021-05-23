class Solution {
public:
    
    int n;
    vector<bool> visited;
    vector<int> singlePath;
    vector<vector<int>> paths;
        
    void dfs(int v, vector<vector<int>> &Adj) {
        singlePath.push_back(v);
        
        if (v == n - 1) {   
            paths.emplace_back(singlePath);
            return;
        }
        
        for (int u : Adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                dfs(u, Adj);
                visited[u] = false;
                singlePath.pop_back();
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        visited.resize(n, false);
        dfs(0, graph);
        return paths;
    }
};
