class Solution {
public:
    
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        vector<int> ans(queries.size());
        for (int i = 1; i < arr.size(); ++i) arr[i] ^= arr[i - 1];        
        
        for (int i = 0; i < queries.size(); ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            ans[i] = l != 0 ? arr[r] ^ arr[l - 1] : arr[r];
        }        
        return ans;
    }
};
