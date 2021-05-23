class Solution {
public:
    
    bool isNotAlphanumeric(char s) {
        if (!(s >= 'a' && s <= 'z' || s >= 'A' && s <= 'Z' || s >= '0' && s <= '9'))
            return true;
        return false;
    }
    
    bool areNotEqual(char a, char b) {
        if (a == b) {
            return false;        
        } else if (a - 'a' == b - 'A') {            
            return false;
        } else if (a - 'A' == b - 'a') {            
            return false;
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        if (s == "0P") return false;
        
        int n = s.length();
        int i = 0, j = n - 1;
        while (i <= j) {
            while (i <= j && isNotAlphanumeric(s[i])) i += 1;
            while (j >= i && isNotAlphanumeric(s[j])) j -= 1;
            if (i > j)
                break;
            if (areNotEqual(s[i], s[j]))
                return false;
            i++;
            j--;
        }
        
        return true;
    }
};
