class Solution {
public:
    int maxArea(vector<int>& nums) {
        
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int maxarea = 0 ;

        while(left < right){
            int area = min(nums[left], nums[right]) * (right-left);
            maxarea = max(maxarea, area);

            if(nums[left]<nums[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxarea;
    }
};