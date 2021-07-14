class FreqStack {
public:
    
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> S;
    int maxFreq = 0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val] += 1;
        if (S.find(freq[val]) == S.end()) {
            stack<int> temp;
            temp.push(val);
            S.insert({freq[val], temp});
        } else {
            S[freq[val]].push(val);
        }
        maxFreq = max(maxFreq, freq[val]);
    }
    
    int pop() {
        int popped = S[maxFreq].top(); 
        S[maxFreq].pop();
        freq[popped] -= 1;
        if (S[maxFreq].empty())
            maxFreq -= 1;
        return popped;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */