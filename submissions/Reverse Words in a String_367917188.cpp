class Solution {
public:
    string reverseWords(string s) {
        if (s.length() == 0) return "";
        int i = 0, n = s.length();
        while (i < n && s[i] == ' ') i += 1;
        s = s.substr(i, n - i + 1);
        n = s.length(), i = n - 1;
        while (i >= 0 && s[i] == ' ') i -= 1;
        s = s.substr(0, i + 1);
        n = s.length();
        reverse(s.begin(), s.end());
        int j = 0;
        for (i = 0; i < n; ++i) {
            int t;
            while (i < n && s[i] != ' ') i += 1;
            t = i;
            i -= 1;
            while (j < i) swap(s[j++], s[i--]);
            if (t >= n) break;
            j = i = t;
            while (i < n && s[i] == ' ') i += 1;
            i -= 1;
            if (j != i) s.replace(j, i - j + 1, " ");
            j += 1;
            i = j;
            n = s.length();
        }
        return s;
    }
};
