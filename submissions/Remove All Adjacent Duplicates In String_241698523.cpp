class Solution {
public:
    string removeDuplicates(string S) {
        if (S.length() == 0)
            return "";
        
        stack<char> st;
        for (int i = 0; i < S.length(); ++i) {
            if (!st.empty() && st.top() == S[i]) {
                st.pop();
                continue;
            }
            st.push(S[i]);
        }
        
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
