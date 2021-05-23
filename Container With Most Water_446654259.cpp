class Solution {
public:
    int maxArea(vector<int>& A) {
        int i = 0, j = A.size() - 1;
        int maxArea = min(A[i], A[j]) * (j - i);
        while (i < j) {
            int area = min(A[i], A[j]) * (j - i);
            if (area > maxArea)
                maxArea = area;
            if (A[i] <= A[j])
                i += 1;
            else
                j -= 1;
        }
        return maxArea;
    }
};
