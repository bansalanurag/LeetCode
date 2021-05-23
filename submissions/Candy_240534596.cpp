class Solution {
public:
    int candy(vector<int>& ratings) {
        int result = -1;
        vector<int> candies(ratings.size());
        candies[0] = 1;
        
        for (int i = 1; i < candies.size(); ++i) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
            else
                candies[i] = 1;
        }
        
        result = candies[candies.size() - 1];
        for (int i = candies.size() - 2; i >= 0; --i) {
            int curr = 1;
            if (ratings[i] > ratings[i + 1])
                curr = candies[i + 1] + 1;
            result += max(curr, candies[i]);
            candies[i] = curr;
        }
        
        return result;
    }
};
