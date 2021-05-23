class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> S;
        for (string s : emails) {
            string t = s, k = "";
            int plus = s.find('+');
            int atrate = s.find('@');
            if (plus != string::npos) t = s.substr(0, plus) + s.substr(atrate);
            bool atratepassed = false;
            for (char i : t) {
                if (i == '@') atratepassed = true;
                if (!atratepassed && i == '.') continue;
                k += i;
            }
            S.insert(k);
        }
        return (int) S.size();
    }
};
