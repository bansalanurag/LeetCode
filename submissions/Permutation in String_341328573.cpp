class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        int total = 0;
        vector<int> A(26, 0);
        for (char i : s1) {            
            A[i - 'a'] += 1;
            total += 1;
        }
        
        for (int i = 0; i < s2.length(); ++i) {
            int j = i;
            int s = total; 
            vector<int> B = A; 
            while (i < s2.length() && B[s2[i] - 'a'] != 0) {
                B[s2[i] - 'a'] -= 1;
                s -= 1;
                i++;
            }
            if (s == 0)
                return true;
            i = j;
        }
        
        return false;
    }
};
