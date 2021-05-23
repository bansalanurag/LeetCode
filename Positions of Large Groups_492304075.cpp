class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> indexes;

        for (int i = 0; i < S.length(); ++i) {
            int s = i, e = i;
            while (e < S.length() && S[s] == S[e]) {
                e += 1;
            }

            if (e - s >= 3) {
                vector<int> pos{s, e - 1};
                indexes.push_back(pos);
            }

            if (s != e)
                i = e - 1;
        }

        return indexes;
    }
};
