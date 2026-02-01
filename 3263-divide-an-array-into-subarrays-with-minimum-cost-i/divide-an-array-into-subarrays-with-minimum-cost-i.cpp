class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum =0;
        
    
        int min1 = 100; 
        int min2 = 100;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < min1){
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2){
                min2 = nums[i];
            }
        }
        sum= nums[0] + min1+ min2;
        return sum;

        
        
    }
};