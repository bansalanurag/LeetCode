class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        multiset<int> squares;
        for (int i : nums)
            squares.insert(i * i);
        for (int i : squares) ans.push_back(i);
        return ans;
    }
};
