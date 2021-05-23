class Solution {
public:
    int countElements(vector<int>& arr) {
        if (arr.size() == 0) return 0;
        int ans = 0, maxNum = 0;
        for (int i : arr) maxNum = max(maxNum, i);
        vector<int> C(maxNum + 1, 0);
        for (int i : arr) C[i] += 1;
        for (int i = 0; i < C.size() - 1; ++i) if (C[i] > 0 && C[i + 1] > 0) ans += C[i];
        return ans;
    }
};
