class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {

        //brute force

        //we start with the first thing is that traversing through the array and seeing whether the next number is greater than the current or not. as soon as this is not satisfied, we return the index.

        int n = nums.size();
        
        for(int i =0 ; i<n; i++){
            if(nums[i]>nums[i+1]){
                return i;
            }
        }
        return -1;
        
    }
};