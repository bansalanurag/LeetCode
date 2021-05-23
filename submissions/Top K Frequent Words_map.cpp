class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        vector<string> ans;
        vector<vector<string>> A(n, vector<string> ());
        map<string, int> M;
        for (string w : words) M[w] += 1;
        for (auto i : M)  A[i.second].push_back(i.first);
        for (int i = n - 1; i >= 0 && k > 0; --i) {
            for (int j = 0; j < A[i].size() && k-- > 0; ++j)
                ans.push_back(A[i][j]);
        }
        return ans;
    }
};
