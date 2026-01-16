class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;
        stack<int> st;

        // build next greater map for nums2
        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                nge[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // remaining elements have no next greater
        while (!st.empty()) {
            nge[st.top()] = -1;
            st.pop();
        }

        // answer nums1 using map
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nge[num]);
        }

        return ans;
    }
};








