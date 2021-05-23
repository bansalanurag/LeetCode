class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans(k);
        priority_queue<pair<int, int>> pq;
        
        for (int i : arr) {
            if (pq.size() < k) {
                int dist = abs(i - x);
                pq.push({dist, i});
                continue;
            }
            
            pair<int, int> p = pq.top();
            int dist1 = p.first;
            int dist2 = abs(i - x);
            
            if (dist1 == dist2) {
                if (p.second > i) {
                    pq.pop();
                    pq.push({dist2, i});
                }
            } else if (dist2 < dist1) {
                pq.pop();
                pq.push({dist2, i});
            }
        }
        
        int idx = 0;
        while (!pq.empty()) {
            ans[idx++] = pq.top().second;
            pq.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};