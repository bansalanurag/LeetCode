class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;        
        
        bool purchase = false;
        int profit = 0;
        int buy;
        int sell;
        buy = sell = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (purchase && prices[i] < sell) {
                profit += sell - buy;
                purchase = false;
                buy = sell = prices[i];
                continue;
            }
            if (prices[i] < buy) {
                buy = prices[i];         
                if (!purchase)
                    sell = buy;
            } else if (prices[i] > sell) {
                sell = prices[i];
                if (sell > buy)
                    purchase = true;
            }
            if (i == prices.size() - 1 && purchase)
                profit += sell - buy;
        }
        return profit;
    }
};
