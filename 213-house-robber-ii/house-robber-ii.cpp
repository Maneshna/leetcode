class Solution {
public:
    int robRange(vector<int>&nums, int l, int r){
        int prev2=0, prev1 =0;
        for(int i =l;i<=r;i++){
            int current = max(prev1, nums[i]+prev2);

            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
    
    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums[0];

        int firstExclude = robRange(nums, 1, n-1);
        int lastExclude = robRange(nums, 0, n-2);

        return max(firstExclude, lastExclude);
        

        
    }
    
};