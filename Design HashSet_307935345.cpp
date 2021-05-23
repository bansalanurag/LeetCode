class MyHashSet {
public:
    /** Initialize your data structure here. */
    
    int A[(int) 1e6 + 1]; 
    int mod = (int) 1e6;
    
    MyHashSet() {
        memset(A, -1, sizeof(A));
    }
    
    void add(int key) {
        A[key % mod] = key;
    }
    
    void remove(int key) {
        A[key % mod] = -1;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {        
        return A[key % mod] != -1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
