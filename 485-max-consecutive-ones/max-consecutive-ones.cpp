class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int count=0;
        for(int right =0; right<n; right++){
            if(nums[right]==0){
                left = right +1; //move the entire sliding window from that position as soon as u encounter 1. and keep a track of the number of the 1s u have seen

            }
            else{
                count = max(count, right-left+1); //max of the current sliding window with ones and the prev max stored
            }
        }
        return count;    }
};