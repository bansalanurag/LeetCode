class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        if (ops.empty())
            return sum;
        
        stack<int> S;
        for (auto operation : ops) {
            if (operation == "C") {                
                S.pop(); 
            } else if (operation == "D") {
                S.push(S.top() * 2);
            } else if (operation == "+") {
                int a = S.top(); S.pop();
                int b = S.top(); S.push(a);
                S.push(a + b);
            } else {
                int num = operation[0] == '-' ? stoi(operation.substr(1)) * -1 : stoi(operation);
                S.push(num);
            }
        }        
        
        while (!S.empty()) {
            sum += S.top();
            S.pop();
        }
        
        return sum;
    }
};