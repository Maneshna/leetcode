class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int maxArea =0;
        int left =0;
        int right = n-1;
        while(left<right){
            int currentArea = min(nums[right], nums[left]) * (right-left);
            maxArea = max(currentArea, maxArea);
            if(nums[left]<nums[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
        
    }
};