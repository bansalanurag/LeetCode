class Solution {
public:
    
    /*bool binarySearch(vector<pair<int, int>> &A, pair<int, int> target) {
        int l = 0, h = A.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (A[m].first == target.first && A[m].second == target.second)
                return true;
            else if (A[m].first < target.first)                
                l = m + 1;
            else 
                h = m - 1;
        }
        
        return false;
    }*/
    
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator () (std::pair<T1, T2> const &pair) const
        {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);

            return h1 ^ h2;
        }
    };
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dir = 0, x = 0, y = 0;
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        
        
        /*vector<pair<int, int>> O(obstacles.size());
        int k = 0;
        for (auto i : obstacles) O[k++] = {i[0], i[1]};
        sort(O.begin(), O.end(), [] (const pair<int, int> a, const pair<int, int> b) {
            if (a.first < b.first)
                return true;
            else if (a.first == b.first && a.second < b.second)
                return true;
            return false;
        });*/
        
        unordered_set<pair<int, int>, pair_hash> S;
        for (auto i : obstacles) S.insert({i[0], i[1]});
        
        
        int ans = 0;
        for (int i : commands) {
            if (i == -2) {
                dir = (dir + 3) % 4;
            } else if (i == -1) {
                dir = (dir + 1) % 4;
            } else {
                for (int k = 0; k < i; ++k) {
                    int nx = x + dr[dir];
                    int ny = y + dc[dir];
                    if (S.find({nx, ny}) == S.end()) {
                        x = nx;
                        y = ny;                        
                    } else
                        break;
                    ans = max(ans, x * x + y * y);
                }
            }
        }
        
        return ans;
    }
};
