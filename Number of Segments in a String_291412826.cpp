class Solution {
public:
    int countSegments(string s) {
        string t;
        int c = 0;
        istringstream in(s);
        while(in >> t) c++;
        return c;
    }
};
