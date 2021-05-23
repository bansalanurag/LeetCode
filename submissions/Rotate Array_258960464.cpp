class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> A(nums.size());
        for (int i = 0; i < nums.size(); ++i)   A[(i + k) % A.size()] = nums[i];
        for (int i = 0; i < nums.size(); ++i)   nums[i] = A[i];            
    }
};
