class Solution {
public:
    vector<vector<int>> adj;
    vector<char> visited;
    
    bool dfs(int v) {
    visited[v] = 1;
    for (int u : adj[v]) {
        if (visited[u] == 0) {
            if (dfs(u))
                return true;
        } else if (visited[u] == 1) {
            return true;
        }
    }
    visited[v] = 2;
    return false;
}
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> temp;
        adj.resize(numCourses, temp);
    
        for (int i = 0; i < prerequisites.size(); ++i)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
    
        for (int i = 0; i < numCourses; ++i) {
            visited.clear();
            visited.resize(numCourses, 0);
            if (dfs(i))
                return false;
        }
        return true;
    }
};
