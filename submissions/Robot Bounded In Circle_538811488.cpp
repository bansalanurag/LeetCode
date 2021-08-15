class Solution {
public:
    
    void makeMove(int &x, int &y, int &dir) {
        if (dir == 0) { // North
            y += 1;
        } else if (dir == 2) { // South
            y -= 1;
        } else if (dir == 1) { // East
            x += 1;
        } else { // West
            x -= 1;
        }
    }
    
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dir = 0;
        
        for (int k = 0; k < 4; ++k) {
            for (char d : instructions) {                  
                if (d == 'G') {
                    makeMove(x, y, dir);
                } else if (d == 'L') {
                    dir = (4 + dir - 1) % 4;
                } else if (d == 'R') {
                    dir = (dir + 1) % 4;
                }                 
            }
            
            if (x == 0 && y == 0) 
                return true;
        }
        
        return false;
    }
};