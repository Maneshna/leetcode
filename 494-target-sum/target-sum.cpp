class Solution {
public:

    int solve(int index, int sum, vector<int>& nums, int target){
        if(index == nums.size()){
            return (sum == target);
        }

        int add = solve(index+1, sum+nums[index], nums, target);

        int subtract = solve(index+1, sum-nums[index], nums, target);

        return add+subtract;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,0, nums, target);
        
    }
};