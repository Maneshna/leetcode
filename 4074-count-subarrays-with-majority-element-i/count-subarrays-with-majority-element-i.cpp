class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        //we will start by  brute force approch of using sliding window in this.
        int n = nums.size();
        int totalsubarrays = 0;
        for(int i =0; i<n; ++i){
            int targetcount =0;

            for(int j =i; j<n; ++j){
                if(nums[j]==target){
                    targetcount++;
                }
                int windowsize =j-i+1;

                if(targetcount > windowsize/2){
                    totalsubarrays++;
                }
            }
        }
        return totalsubarrays;
        
    }
};