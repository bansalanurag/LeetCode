class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string dest = "";
        if (paths.empty()) 
            return dest;
        
        unordered_set<string> Roads, cities;                
        for (vector<string> path : paths) {
            Roads.insert(path[0]);
            cities.insert(path[0]);
            cities.insert(path[1]);
        }
        for (string city : cities) {
            if (Roads.find(city) == Roads.end())
                dest = city;
        }
        
        return dest;
    }
};