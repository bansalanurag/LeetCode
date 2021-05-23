class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool ans = true;
        queue<int> Q;
        int n = graph.size();
        vector<int> visited(n, -1);
                
        for (int i = 0; i < n; ++i) {
            if (visited[i] == -1) {
                Q.push(i);
                visited[i] = 0;
                while (!Q.empty()) {
                    int v = Q.front(); Q.pop();
                    int color = visited[v];
                    for (auto u : graph[v]) {
                        if (visited[u] == -1) {
                            visited[u] = color ^ 1;
                            Q.push(u);
                        } else if (visited[u] == color) {
                            ans = false;
                            break;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
