class Solution {
public:
    int findJudge(int N, vector<vector<int>>& E) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        vector<int> in(N, 0), out(N, 0);
        for (auto i : E) {
            in[i[1] - 1] += 1;
            out[i[0] - 1] += 1;
        }
        
        for (int i = 0; i < N; ++i) {
            if (in[i] == N - 1 && out[i] == 0)
                return (i + 1);
        }
        return -1;
    }
};
