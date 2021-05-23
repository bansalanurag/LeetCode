class Solution {
public:
    
    unordered_map<int, int> M;
    
    int countWays(string s, int i, int n) {        
        if (i >= n)
            return 1;
        
        if (s[i] == '0')
            return 0;
        
        if (M.find(i) != M.end())
            return M[i];
                
        int ways = countWays(s, i + 1, n);
        if (i + 2 <= n && stoi(s.substr(i, 2)) <= 26)
            ways += countWays(s, i + 2, n);
        
        return M[i] = ways;
    }
    
    int numDecodings(string s) {
        return countWays(s, 0, s.length());
    }
};
