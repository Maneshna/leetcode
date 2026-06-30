class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = nums[0];
        int currentsum = 0;
        int left = 0;
        for(int right = 0; right<n; right++){
            currentsum = currentsum + nums[right];

            if(currentsum > maxsum ){
                maxsum = currentsum;
            }

            if(currentsum <0){
                currentsum = 0;
                left = right +1;
            }

        }
        return maxsum;
        
    }
};