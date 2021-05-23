class Solution {
public:
    
    int findOccurence(vector<int> &A, int target, bool first) {
        int l = 0, h = A.size() - 1;
        int ans = -1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (A[m] == target) {
                ans = m;
                if (first)
                    h = m - 1;
                else
                    l = m + 1;
            } else if (A[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = findOccurence(nums, target, true);
        int l = findOccurence(nums, target, false);
        vector<int> ans{f, l};
        return ans;
    }
};
