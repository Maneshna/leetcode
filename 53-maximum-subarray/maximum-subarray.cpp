class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int best = nums[0];
        int current =nums[0];
        int left =0;
        for(int right =1; right < n; right++){
            current = max(nums[right], current+nums[right]); //checking whether the current one is the greatest one of the previous sums will be 
            
            best = max(current,best); // gloablly checking the maxium 

            
        }
        return best;

        
    }
};