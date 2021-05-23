class FirstUnique {
    
    queue<int> Q;
    unordered_map<int, int> hash;
    
public:
    FirstUnique(vector<int>& A) {
        for (auto i : A) {
            Q.push(i);
            hash[i] += 1;
        }
    }
    
    int showFirstUnique() {
        while (!Q.empty() && hash[Q.front()] != 1) {            
            Q.pop();
        }
        return Q.empty() ? -1 : Q.front();
    }
    
    void add(int value) {
        Q.push(value);
        hash[value] += 1;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
