class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int numOperations = 0;
        int prev = 0;
        
        for (int element : target) {
            if (element > prev)
                numOperations += element - prev;
            prev = element;
        }
        
        return numOperations;
    }
};
