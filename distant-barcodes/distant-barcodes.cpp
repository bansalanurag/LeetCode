class Solution {
public:
    
    // Time : O(N log K) , Space : O(K)
    // N -> size of input array
    // K -> unique elements in input array
    
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> ans(barcodes.size());
        priority_queue<pair<int, int>> maxHeap;
        unordered_map<int, int> freq;
        
        for (int b : barcodes) freq[b] += 1;
        for (auto i : freq) maxHeap.push({i.second, i.first});
                
        for (int i = 0; i < ans.size(); ++i) {
            pair<int, int> p = maxHeap.top();
            maxHeap.pop();
            
            if (i == 0) {
                ans[i] = (p.second);
                p.first -= 1;
                maxHeap.push(p);
                continue;
            }
            
            stack<pair<int, int>> S;
            while (!maxHeap.empty() && ans[i - 1] == p.second) {
                S.push(p);
                p = maxHeap.top();
                maxHeap.pop();
            }
            
            while (!S.empty()) {
                maxHeap.push(S.top());
                S.pop();
            }
            
            ans[i] = (p.second);
            p.first -= 1;
            maxHeap.push(p);                
        }
        
        return ans;
    }
};