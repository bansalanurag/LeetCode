class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits, letter;
        for (string log : logs) {                       
            if (log[log.length() - 1] >= '0' && log[log.length() - 1] <= '9') {
                digits.push_back(log);
            } else 
                letter.push_back(log);
        }
        
        sort(letter.begin(), letter.end(), [] (const string a, const string b) {           
            int i1 = 0;
            int i2 = 0;

            while (a[i1 ++] != ' ');
            while (b[i2 ++] != ' ');

            int comp = a.compare (i1, a.size () - i1 + 1, b, i2, b.size () - i2 + 1);
            if (comp == 0) {
                comp = a.compare (0, i1 - 2, b, 0, i2 - 2);
            }

            return comp < 0;    
        });
        
        for (string log : digits) letter.push_back(log);
        return letter;
    }
};
