class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> st;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];

            // Pop elements that are smaller than or equal to the current element
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }

            // If stack is empty, no greater element exists to the right
            if (st.empty()) {
                next_greater[num] = -1;
            } else {
                next_greater[num] = st.top();
            }

            // Push current element to stack for elements on its left
            st.push(num);
        }

        // Build the result for nums1 using the map
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(next_greater[num]);
        }

        return ans;
    }
};