class TreeAncestor {
public:
    
    int n;
    int log;
    vector<vector<int>> up;
    vector<int> depth;
    
    TreeAncestor(int n, vector<int>& parent) {
        log = 0;
        while (n > (1 << log))
            log += 1;
        
        up.resize(n, vector<int> (log));
        depth.resize(n, 0);
        parent[0] = 0;
        for (int i = 0; i < n; ++i) {
            up[i][0] = parent[i];
            if (i != 0)
                depth[i] = depth[parent[i]] + 1;
            for (int j = 1; j < log; ++j) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        if (k > depth[node])
            return -1;
        
        for (int j = 0; j < log; ++j) {
            if (k & (1 << j)) {
                node = up[node][j];
            }
        }
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
