class Solution {
public:
    int myAtoi(string str) {
        if (str.length() == 0)
            return 0;
        
        int n = str.length();
        double ans = 0;
        int i = 0;
        int rem = 1;
        bool neg = false;
        
        while (i < n && str[i] == ' ')
            ++i;
        
        if (str[i] == '-') {
            neg = true;
            i += 1;
        } else if (str[i] == '+')
            i += 1;
        
        while (i < n && str[i] == '0')
            ++i;
        while (i < n && (str[i] >= '0' && str[i] <= '9')) {
            ans = ans * 10 + (str[i] - '0');
            ++i;        
        }
                        
        if (neg)
            ans = ans * (-1);
        if (ans > INT_MAX)
            return INT_MAX;
        if (ans < INT_MIN)
            return INT_MIN;
        return ans;
    }
};
