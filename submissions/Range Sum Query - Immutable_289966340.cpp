class NumArray {
public:
    vector<int> P;
    NumArray(vector<int>& nums) {
        P.resize(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i)
            P[i] = i == 0 ? nums[i] : P[i - 1] + nums[i];        
    }
    
    int sumRange(int i, int j) {
        return i == 0 ? P[j] : P[j] - P[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
