class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for (int x : nums1) {
            int idx = -1;

            // find index of x in nums2
            for (int i = 0; i < nums2.size(); i++) {
                if (nums2[i] == x) {
                    idx = i;
                    break;
                }
            }

            int nextGreater = -1;

            // search to the right
            for (int j = idx + 1; j < nums2.size(); j++) {
                if (nums2[j] > x) {
                    nextGreater = nums2[j];
                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};







