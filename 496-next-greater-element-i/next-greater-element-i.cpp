class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> st;

       
       
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];

           
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }

          
            if (st.empty()) {
                next_greater[num] = -1;
            } else {
                next_greater[num] = st.top();
            }

            
            st.push(num);
        }

      
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(next_greater[num]);
        }

        return ans;
    }
};