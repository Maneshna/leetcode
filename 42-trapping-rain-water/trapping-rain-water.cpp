class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        int left =0;
        int right = n-1;
        int leftmax = 0;
        int rightmax = 0;

        while(left < right){
            leftmax = max(leftmax, nums[left]);
            rightmax = max(rightmax, nums[right]);

            if(leftmax < rightmax){
                ans += leftmax - nums[left];
                left++;
            }
            else{
                ans += rightmax - nums[right];
                right--;
            }
        }
        return ans;
        
    }
};