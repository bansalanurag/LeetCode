class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 1;
        for (;;++i) {
            if (!binary_search(arr.begin(), arr.end(), i)) {
                k--;
                if (!k)
                    break;
            }
        }
        return i;
    }
};
