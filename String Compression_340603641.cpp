class Solution {
public:
    
    vector<char> getDigits(int n) {
        vector<char> digits;
        while (n) {
            digits.push_back('0' + (n % 10));
            n /= 10;
        }        
        reverse(digits.begin(), digits.end());
        return digits;
    }
    
    int compress(vector<char>& A) {
        if (A.empty()) 
            return 0;
        
        int j = 0, i = 0;
        int count = 1;
        for (; i < A.size() - 1; ++i) {            
            if (A[i] != A[i + 1]) {
                A[j++] = A[i];
                if (count != 1) {
                    vector<char> num = getDigits(count);
                    for (int k = 0; k < num.size(); ++k) {
                        A[j++] = num[k];                    
                    }
                }
                count = 1;
            } else
                count += 1;
        }
        
        if (j == 0 && count == 1) return 1;
        
        A[j++] = A[i];
        if (count != 1) {
            vector<char> num = getDigits(count);
            for (int k = 0; k < num.size(); ++k) {
                A[j++] = num[k];                    
            }
        }
        
        return j;
    }
};
