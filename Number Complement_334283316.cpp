class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        
        int temp = 0;
        bool leftmost = false;
        for (int i = 31; i >= 0; --i) {
            if (!leftmost && (num&(1 << i))) 
                leftmost = true;                
            
            if (leftmost)
                temp |= (1 << i);
        }
        
        // long temp = 0;
        // int i = 0;
        // while ((long) num >= (1 << i)) {
        //     temp |= (1 << i++);
        // }
        
        return (num^temp);
    }
};
