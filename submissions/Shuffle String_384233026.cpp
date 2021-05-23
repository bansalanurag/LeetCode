class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = "";
        vector<char> A(s.length());
        
        for (int i = 0; i < s.length(); ++i) 
            A[indices[i]] = s[i];
        
        for (char i : A) ans += i;
        
        return ans;
    }
};
