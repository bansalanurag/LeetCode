class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        /*if (s.length() == 0) return 0;
        int ans = 0, n = s.length();
        int count = 0;
        unordered_map<string, int> M;
        for (int k = minSize; k <= maxSize; ++k) {
            for (int i = 0; i < i + k && i + k <= n; ++i) {
                count = 0; 
                int C[26];
                memset(C, 0, sizeof(C));
                string sub = s.substr(i, k);
                for (int j = 0; j < k; ++j) {
                    if (C[sub[j] - 'a'] == 0) count += 1;                                    
                    C[sub[j] - 'a'] += 1;                
                    if (count > maxLetters) break;                
                }
                if (count <= maxLetters) {
                    M[sub] += 1;
                    ans = max(ans, M[sub]);
                }
            }
        }
        return ans;*/
        
        vector<int> m(26, 0);
        unordered_map<string, int> strs;
        for(int i = 0, j = 0, count = 0, size = s.size(); j < size; ++j) {
            if(++m[s[j]-'a'] == 1) ++count;
            if(j-i+1 > minSize)
                if(--m[s[i++]-'a'] == 0) --count;
            if(j-i+1 >= minSize && count <= maxLetters) ++strs[s.substr(i, j-i+1)];
            while(count > maxLetters) 
                if(--m[s[i++]-'a'] == 0) --count;
        }
        int max_ = 0;
        for(const auto &kv: strs) max_ = max(max_, kv.second);
        return max_;
    }
};
