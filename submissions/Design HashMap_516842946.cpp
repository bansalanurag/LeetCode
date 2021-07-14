class MyHashMap {
public:    
    /** Initialize your data structure here. */
    
    const int N = 1000001;
    vector<int> Key, Value;
    
    MyHashMap() {
        Key.resize(N, -1);
        Value.resize(N, -1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = key % N;
        Key[idx] = Value[idx] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = key % N;
        return Key[idx] != -1 ? Value[idx] : -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        Key[key % N] = Value[key % N] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */