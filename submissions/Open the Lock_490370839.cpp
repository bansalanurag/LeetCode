class Solution {
public:
    
    // 0000 -> [0001, 0010, 0100, 1000], [9000, 0900, 0090, 0009]
    int addNextCombinations(queue<string> &Q, unordered_set<string> &locks, unordered_set<string> &visited, string 
        &s) {
        int nextCnt = 0;
        
        for (int i = 0; i < 4; ++i) {
            int num =  s[i] - '0';
            char nxt = ((num + 1) >= 10 ? 0 : num + 1) + '0';
            char prv = ((num - 1) < 0 ? 9 : num - 1) + '0';
            
            string next = s.substr(0, i) + nxt + s.substr(i + 1);
            string prev = s.substr(0, i) + prv + s.substr(i + 1);
            
            if (visited.find(next) == visited.end() && locks.find(next) == locks.end()) {
                Q.push(next);
                visited.insert(next);
                nextCnt += 1;
            }
            if (visited.find(prev) == visited.end() && locks.find(prev) == locks.end()) {
                Q.push(prev);
                visited.insert(prev);
                nextCnt += 1;
            }
        }
        
        return nextCnt;
    }
    
    int openLock(vector<string>& deadends, string target) {
        queue<string> Q;
        unordered_set<string> visited;
        unordered_set<string> locks;
        for (auto i : deadends) {
            if (i == "0000" || i == target)
                return -1;
            locks.insert(i);
        }
        
        Q.push("0000");
        visited.insert("0000");
        int curr = 1, next = 0;
        bool found = false;
        int moves = 0;
        
        while (!Q.empty()) {
            string currentCombination = Q.front(); Q.pop();
            curr -= 1;
            
            if (currentCombination == target) {
                found = true;
                break;
            }
            
            next += addNextCombinations(Q, locks, visited, currentCombination);
            
            if (curr == 0) {
                curr = next;
                next = 0;
                moves += 1;
            }
        }
        
        return found ? moves : -1;
    }
};
