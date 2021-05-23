class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> Adj(n, vector<int> ());
        vector<int> deg(n, 0);
        vector<int> leaves;
        
        for (auto j : edges) {            
            Adj[j[0]].push_back(j[1]);
            Adj[j[1]].push_back(j[0]);
            
            deg[j[0]] = Adj[j[0]].size();            
            deg[j[1]] = Adj[j[1]].size();
        }
        
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 0 || deg[i] == 1) {
                deg[i] = 0;
                leaves.push_back(i);
            }
        }
        
        int count = leaves.size();
        while (count < n) {
            vector<int> newleaves;
            for (auto u : leaves) {
                for (int v : Adj[u]) {
                    deg[v] -= 1;
                    if (deg[v] == 1)
                        newleaves.push_back(v);
                }
                deg[u] = 0;
            }
            count += newleaves.size();
            leaves = newleaves;
        }
        
        return leaves;        
    }
};
