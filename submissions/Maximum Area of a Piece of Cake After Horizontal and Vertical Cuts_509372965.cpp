class Solution {
public:
    
    const int mod = (int) 1e9 + 7;
    
    int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
        sort(H.begin(), H.end());
        sort(V.begin(), V.end());

        long long int maxHori = max(H[0], h - H[H.size() - 1]);
        long long int maxVert = max(V[0], w - V[V.size() - 1]);
        
        for (int i = 1; i < H.size(); ++i) {
            maxHori = max<long long int>(maxHori, H[i] - H[i - 1]);
        }
        for (int i = 1; i < V.size(); ++i) {
            maxVert = max<long long int>(maxVert, V[i] - V[i - 1]);
        }
        
        return ((maxVert % mod) * (maxHori % mod)) % mod;
    }
};