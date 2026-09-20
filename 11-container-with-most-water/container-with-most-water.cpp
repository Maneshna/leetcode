class Solution {
public:
    int maxArea(vector<int>& nums) {
        int left =0;
        int n =nums.size();
        int right = n-1;
        int maxArea =0;
        while(left<right){
            int currentArea = min(nums[left], nums[right]) * (right-left);
            maxArea =max(currentArea, maxArea);

            if(nums[left]>nums[right]){
                right--;
            }else{
                left++;
            }
        }
        return maxArea;
        
    }
};