class OrderedStream {
public:
    
    int nextId = 1;
    vector<string> V;
    
    OrderedStream(int n) {
        V.resize(n + 1, "");
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> chunk;
        V[idKey] = value;
        
        if (idKey == nextId) {
            while (nextId < V.size() && V[nextId] != "") {
                chunk.push_back(V[nextId]);
                nextId += 1;
            }
        }
        
        return chunk;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */