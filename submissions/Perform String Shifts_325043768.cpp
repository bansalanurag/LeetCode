class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        if (shift.size() == 0) return s;
        int t = 0, n = s.length();        
        for (auto i : shift) t = (i[0] == 0) ? t - i[1] : t + i[1];
        cout << t << "\n";
        if (t == 0) return s;
        else if (t < 0) {
            t = -1 * t;
            t %= s.length();
            s = s.substr(t) + s.substr(0, t);
        } else {            
            t %= s.length();
            s =  s.substr(n - t) + s.substr(0, n - t);
            // s =  s.substr(n - t, n) + s.substr(0, n - t);   
        }             
        return s;
    }
};
