class Solution {
public:
    
    int N;
    vector<int> parent;
    vector<int> size;
    
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    
    int find_set(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find_set(parent[v]);
    }
    
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] > size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        N = isConnected.size();
        parent.resize(N);
        size.resize(N);
        
        for (int i = 0; i < N; ++i) make_set(i);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (isConnected[i][j])
                    union_set(i, j);
            }
        }
        for (int i = 0; i < N; ++i) find_set(i);
        
        unordered_set<int> parents;
        for (int i = 0; i < N; ++i) parents.insert(parent[i]);
        
        return (int) parents.size();
    }
};