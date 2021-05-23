class MedianFinder {
public:
    
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
    
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (low.empty()) {
            low.push(num);
            return;
        }
        
        // Add
        if (low.top() < num)
            high.push(num);
        else
            low.push(num);
        
        // Rebalance
        if (abs((int) low.size() - (int) high.size()) > 1) {
            if (low.size() < high.size()) {
                low.push(high.top());
                high.pop();
            }
            else {
                high.push(low.top());
                low.pop();
            }
        }
    }
    
    double findMedian() {
        if (low.size() == high.size()) {
            return (low.top() + high.top()) / 2.0;
        } else if (low.size() > high.size())
            return low.top();
        else
            return high.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
