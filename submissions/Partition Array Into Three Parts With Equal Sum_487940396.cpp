class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for (int i : arr) sum += i;
        
        if (sum % 3 != 0)
            return false;
        
        sum /= 3;
        int currSum = 0;        
        int cnt = 0;
        for (int i = 0; i < arr.size(); ++i) {
            currSum += arr[i];
            
            if (currSum == sum) {
                if (++cnt == 3)
                    return true;                
                currSum = 0;
            }
        }
        
        return false;
    }
};
