class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int a = rec1[0], b = rec1[1], c = rec1[2], d = rec1[3];
        int w = rec2[0], x = rec2[1], y = rec2[2], z = rec2[3];
        
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3] ||
            rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
            // the line cannot have positive overlap
            return false;
        }
        
        if (c <= w || d <= x)
            return false;
        else if (y <= a || z <= b)
            return false;
            
        return true;
        
    }
};
