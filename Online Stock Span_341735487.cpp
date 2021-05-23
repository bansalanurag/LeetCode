class StockSpanner {
public:
    unordered_map<int, int> M;
    stack<int> S;

    
    StockSpanner() {
    
    }
    
    int next(int price) {
        if (S.empty()) {
            S.push(price);
            M[price] = 1;
            return 1;
        }
        int count = 0;
        while (!S.empty() && price >= S.top()) {
            count += M[S.top()];
            S.pop();
        }
        S.push(price);
        M[price] = (count + 1);
        return M[price];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
