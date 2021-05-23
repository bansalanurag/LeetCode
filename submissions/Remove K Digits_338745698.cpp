class Solution {
public:
    
    string GetNonZeroPrefixedString(string S, int i) {
        S = S.substr(0, i) + S.substr(i + 1);
        int j = 0;
        while (j < S.length() && S[j] == '0') j++;
        S = j == S.length() ? "0" : S.substr(j);
        return S;
    }
    
    string removeKdigits(string num, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int n = num.length();
        if (n == 0 || k == n) return "0";
        
        while (k--) {            
            int i = 0;
            while (i < num.length() - 1 && num[i] <= num[i + 1]) i++;            
            num = (i == num.length()) ? num.substr(0, i - 1) : GetNonZeroPrefixedString(num, i);            
        }
        
        return num;
    }
};
