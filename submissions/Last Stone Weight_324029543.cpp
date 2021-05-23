class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int ans = 0;
        if (stones.size() == 0) return ans;
        if (stones.size() == 1) return stones[0];
        
        priority_queue<int> Q;
        for (int i : stones) Q.push(i);
        while (Q.size() > 1) {
            int a = Q.top(); Q.pop();
            int b = Q.top(); Q.pop();
            if (a != b) {
                if (a <= b) 
                    Q.push(b - a);
                else
                    Q.push(a - b);
            }
        }
        return Q.size() != 0 ? Q.top() : 0;
    }
};
