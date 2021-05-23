class Solution {
public:
    vector<int> decompressRLElist(vector<int>& A) {
        vector<int> ans;
        int n = A.size();
        for (int i = 0; i < n - 1; i += 2) {
            int key = A[i];
            int val = A[i + 1];
            while (key--) ans.emplace_back(val);
        }
        return ans;
    }
};
