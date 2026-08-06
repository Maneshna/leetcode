class Solution {
public:

    int solve(int index, vector<int> &nums, vector<int> &dp){
        if(index >= nums.size()){
            return 0;
        }
        if(dp[index] != -1)
            return dp[index];

        int rob = nums[index] + solve(index+2, nums,dp);
        int skip = solve(index+1, nums,dp);

        return dp[index]=max(rob, skip);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums,dp);

        
    }
};