class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0;
        int maxValid = 0;
        
        for (char c : s) {
            if (c == '(')
                left += 1;
            else
                right += 1;
            
            if (left == right) {
                maxValid = max(maxValid, left + right);                
            } else if (right > left) {
                right = left = 0;
            }
        }
        
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '(')
                left += 1;
            else
                right += 1;
            
            if (left == right)
                maxValid = max(maxValid, left + right);
            else if (left > right)
                right = left = 0;
        }
        
        return maxValid;
    }
};
