class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = INT_MIN;
        int i = 0, j = 0;
        
        int sum = 0;
        while (i < k & i < nums.size()) {
            sum += nums[i++];
        }
        avg = max(avg, (double) sum / k);
        
        while (i < nums.size()) {
            sum -= nums[j++];
            sum += nums[i++];
            avg = max(avg, (double) sum / k);
        }
        
        return avg;
    }
};
