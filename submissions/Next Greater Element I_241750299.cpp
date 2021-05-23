class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> M;
        vector<int> G(nums2.size());
        
        for (int i = nums2.size() - 1; i >= 0; --i) {
            M.insert({nums2[i], i});
            if (st.empty()) {
                st.push(nums2[i]);
                G[i] = -1;
                continue;
            }
        
            if (st.top() > nums2[i]) {
                G[i] = st.top();
            }
            else {
                while (!st.empty() && st.top() <= nums2[i])
                    st.pop();
                !st.empty() ? G[i] = st.top() : G[i] = -1;                
            }        
            st.push(nums2[i]);
        }
        
        vector<int> result;
        for (int i = 0; i < nums1.size(); ++i)
            result.push_back(G[M[nums1[i]]]);
        return result;
    }
};
