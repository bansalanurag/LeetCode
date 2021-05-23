class Solution {
public:
    
    bool checkPos(vector<int>& gas, vector<int>& cost, int i) {
        int j, n = gas.size();        
        int left = (gas[i] - cost[i]) + gas[(i + 1) % n];
        for (j = (i + 1) % n; j != i; j = (j + 1) % n) {
            if (left < cost[j])
                break;
            left = (left - cost[j]) + gas[(j + 1) % n];
        }
        return j == i;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = -1;
        int n = gas.size();
        for (int i = 0; i < n; ++i) {
            if (gas[i] < cost[i])
                continue;
            
            if (checkPos(gas, cost, i)) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
