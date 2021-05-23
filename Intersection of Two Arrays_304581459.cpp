class Solution {
public:
    vector<int> intersection(vector<int>& A, vector<int>& B) {
        vector<int> V;
        unordered_set<int> ans;
        int i = 0, j = 0;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        while (i < A.size() && j < B.size()) {
            if (A[i] < B[j]) i++;
            else if (B[j] < A[i]) j++;
            else { ans.insert(A[i]); i++; j++; }
        }
        for (auto i : ans) V.emplace_back(i); 
        return V;
    }
};
