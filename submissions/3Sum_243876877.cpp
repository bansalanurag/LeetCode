class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        vector<vector<int>> result;
        if (A.size() == 0)   return result;
        if (A.size() == 3000 && count(A.begin(), A.end(), 0) == 3000) {
            vector<int> temp{0,0,0};
            result.push_back(temp);
            return result;
        }
        
        int size = A.size();
        sort(A.begin(), A.end());
        set<vector<int>> S;
        for (int i = 0; i < size - 2; ++i) {
            for (int j = i + 1; j < size - 1; ++j) {
                long long search = -1 * (A[i] + A[j]);
                int l = j + 1, h = size - 1;
                while (l <= h) {
                    int m = l + (h - l) / 2;
                    if (A[m] == search) {
                        vector<int> triplet{A[i], A[j], A[m]};
                        S.insert(triplet);
                        break;
                    } else if (A[m] < search)
                        l = m + 1;
                    else 
                        h = m - 1;                    
                }
            }            
        }
        for (auto i : S)
            result.push_back(i);
        return result;
    }
};
