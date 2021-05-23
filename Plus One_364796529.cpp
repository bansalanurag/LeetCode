class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) { digits.emplace_back(1); return digits; }        
        
        int i = digits.size() - 1;
        int carry = 1;
        while (i >= 0) {
            int sum = carry + digits[i];
            if (sum > 9) {
                carry = sum / 10;
                digits[i] = sum % 10;
            } else {
                digits[i] = sum;
                carry = 0;   
            }
            
            if (carry == 0)
                break;
            i -= 1;
        }
        
        if (carry != 0) {
            vector<int> ans{carry};
            for (auto i : digits) ans.push_back(i);
            return ans;
        }
        
        return digits;
    }
};
