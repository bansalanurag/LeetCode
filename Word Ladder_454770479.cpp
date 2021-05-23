class Solution {
public:
    
    bool isReachable(string from, string to) {
        if (from.length() != to.length()) return false;
        if (from == to) return false;
        
        bool once = false;
        int i = 0, j = 0;
        while (i < from.length()) {
            if (from[i++] != to[j++]) {
                if (!once) {
                    once = true;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool reachable = false;
        for (string s : wordList) {
            if (s == endWord) {
                reachable = true;
                break;
            }
        }
        if (!reachable || beginWord == endWord) return 0;
    
        unordered_map<string, int> Adj;
        int counter = 1;
    
        Adj[beginWord] = 0;
        int src = 0, dest = -1;
        for (string s : wordList) {
            Adj[s] = counter;
            if (s == endWord)
                dest = counter;
            if (s == beginWord)
                src = counter;
            counter += 1;
        }
    
        vector<vector<int>> G(counter, vector<int>());
        for (string s : wordList) {
            if (isReachable(beginWord, s))
                G[Adj[beginWord]].push_back(Adj[s]);
        }
    
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (isReachable(wordList[i], wordList[j])) {
                    G[Adj[wordList[i]]].push_back(Adj[wordList[j]]);
                    G[Adj[wordList[j]]].push_back(Adj[wordList[i]]);
                }
            }
        }
    
    
        int ans = 0;
        queue<int> Q;
        vector<bool> visited(counter, false);
        Q.push(src);
        visited[src] = true;
        int curr = 1, next = 0;
        bool destReached = false;
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            if (v == dest) {
                destReached = true;
                break;
            }
    
            curr -= 1;
            bool addedNext = false;
    
            for (auto u : G[v]) {
                addedNext = true;
                if (!visited[u]) {
                    Q.push(u);
                    visited[u] = true;
                    next += 1;
                }
            }
    
            if (curr == 0) {
                if (!addedNext) {
                    ans = -1;
                    break;
                }
                ans += 1;
                curr = next;
                next = 0;
            }
        }
    
        if (!destReached)
            ans = -1;
    
        return ans + 1;
    }
};
