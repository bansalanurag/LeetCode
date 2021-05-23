class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        unordered_set<string> C;
        C.insert("+");
        C.insert("-");
        C.insert("*");
        C.insert("/");
        
        for (auto i : tokens) {            
            if (C.find(i) == C.end()) {
                S.push(stoi(i));
            } else {
                int a = S.top(); S.pop();
                int b = S.top(); S.pop();
                swap(a, b);
                if (i == "+") {
                    S.push(a + b);
                } else if (i == "-") {
                    S.push(a - b);
                } else if (i == "/") {
                    S.push(a / b);
                } else 
                    S.push(a * b);
            }
        }
        return S.top();
    }
};
