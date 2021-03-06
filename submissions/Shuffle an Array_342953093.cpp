class Solution {
public:
    
    vector<int> backup;
    
    Solution(vector<int>& nums) {
        backup = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return backup;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> temp = backup;
        random_shuffle(temp.begin(), temp.end());
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
