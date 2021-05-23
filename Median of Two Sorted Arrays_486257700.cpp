class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int l = 0, h = n;
        
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            
            int cut1 = mid;
            int cut2 = (n + m) / 2 - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : nums1[cut1];
            int r2 = cut2 == m ? INT_MAX : nums2[cut2];
            
            if (l2 > r1)
                l = mid + 1;
            else if (l1 > r2)
                h = mid - 1;
            else {
                if ((n + m) & 1)
                    return (double) min(r1, r2);
                else
                    return ((double) max(l1, l2) + min(r1, r2)) / 2;
            }
        }
        
        return -1;
    }
};
