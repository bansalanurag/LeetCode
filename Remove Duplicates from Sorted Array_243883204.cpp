class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        if (A.size() == 0)
            return 0;
        
        int slow = 0, fast = 1;
        while (fast < A.size()) {
            while (fast < A.size() && A[slow] == A[fast])  fast += 1;
            if (fast == A.size() && slow == 0)   return 1;            
            if (fast < A.size()) A[++slow] = A[fast++];            
        }
        return (slow + 1);
    }
};
