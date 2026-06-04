class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        for(int i =0; i<n;i++){
            bool left_valid = (i == 0 || nums[i] > nums[i - 1]);
            
            
            bool right_valid = (i == n - 1 || nums[i] > nums[i + 1]);
            
            if (left_valid && right_valid) {
                return i;
            }
        }
        return -1;
        
    }
};