class Solution {
public:
    int totalFruit(vector<int>& tree) {
        // Longest substring having atmost 2 characters.
        
        if (tree.empty())
            return 0;
        
        int left = 0, right = 0;
        int maxLen = 0;
        unordered_map<int, int> M;
        
        while (right < tree.size()) {
            if (M.size() <= 2) {
                M[tree[right]] = right;
                right += 1;
            } 
            
            if (M.size() > 2) {
                int mn = tree.size() + 1;
                int key = 0;
                for (auto i : M) {
                    if (i.second < mn) {
                        mn = i.second;
                        key = i.first;
                    }
                }
                
                left = mn + 1;
                M.erase(key);
            }
            
            maxLen = max(maxLen, right - left);
        }
        
        return maxLen;
    }
};
