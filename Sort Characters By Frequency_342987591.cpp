class Solution {
public:
    string frequencySort(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        string ans = "";
        unordered_map<char, int> M;
        multimap<int, char> F;
        
        for (char i : s) M[i] += 1;
        for (auto i : M) {
            F.insert({i.second, i.first});
        }
                
        for (auto i = F.rbegin(); i != F.rend(); i++) {
            int count = i->first;
            while (count-- > 0)
                ans += i->second;
        }
        
        return ans;
    }
};
