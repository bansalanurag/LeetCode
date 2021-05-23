class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxElements;
        priority_queue<pair<int, int>> maxHeap;
        
        for (int i = 0; i < k && i < nums.size(); ++i)
            maxHeap.push({nums[i], i});        
        maxElements.push_back(maxHeap.top().first);
        
        for (int i = k; i < nums.size(); ++i) {
            maxHeap.push({nums[i], i});
            
            pair<int, int> maxTop = maxHeap.top();
            while (maxTop.second <= i - k && !maxHeap.empty()) {
                maxHeap.pop();
                maxTop = maxHeap.top();
            }
            
            maxElements.push_back(maxTop.first);
        }
        
        return maxElements;
    }
};
