class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        if (arr.empty()) return 0;
        
        int sum = 0, window = 3;
        for (int i : arr) sum += i;
        
        int i = 0;
        while (window - 1 < arr.size()) {
            for (int j = i; j <= i + window - 1; ++j)
                sum += arr[j];
            if (i + window - 1 >= arr.size() - 1) {
                i = 0;
                window += 2;
            } else {
                i += 1;
            }
        }
        
        return sum;
    }
};
