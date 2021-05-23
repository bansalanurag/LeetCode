class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> A, B;
        for (char i : S) {
            if (i == '#') {
                if (!A.empty()) A.pop();
            } else A.push(i);
        }
        for (char i : T) {
            if (i == '#') {
                if (!B.empty()) B.pop();
            } else B.push(i);
        }
        while (!A.empty() && !B.empty()) {
            if (A.top() != B.top()) return false;
            A.pop();
            B.pop();
        }
        if (!A.empty() && B.empty() || A.empty() && !B.empty()) return false;
        return true;
    }
};
