class LRUCache {
public:
    
    int C;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    
    void moveToFront(int key, int val) {
        lru.erase(hash[key]);
        lru.push_front({key, val});
        hash[key] = lru.begin();
    }
    
    LRUCache(int capacity) {
        C = capacity;
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end())
            return -1;
        
        int val = hash[key]->second;
        moveToFront(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if (hash.find(key) != hash.end()) {
            moveToFront(key, value);
            return;
        }
        
        lru.push_front({key, value});
        hash[key] = lru.begin();
        
        if (lru.size() > C) {
            hash.erase(lru.back().first);
            lru.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
