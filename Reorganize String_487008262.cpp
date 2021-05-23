class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> M;
        for (char c : S) M[c] += 1;
        
        priority_queue<pair<int, char>> maxHeap;
        for (auto i : M) maxHeap.push({i.second, i.first});
        
        string ans = "";
        while (!maxHeap.empty()) {
            pair<int, char> p;                        
            stack<pair<int, char>> s;     
            
            while (!maxHeap.empty() && !ans.empty() && maxHeap.top().second == ans[ans.length() - 1]) {
                s.push(maxHeap.top());
                maxHeap.pop();
            }
            
            if (maxHeap.empty())
                return "";
            
            p = maxHeap.top(); maxHeap.pop();
            ans += p.second;
            p.first -= 1;
            if (p.first > 0)
                maxHeap.push(p);
            
            while (!s.empty()) {
                maxHeap.push(s.top());
                s.pop();
            }
        }
        
        return ans;
    }
};
