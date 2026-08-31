class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) sum += num;

        // Base checks
        if (sum % k != 0) return false;
        int target = sum / k;

        // Sorting helps prune early if the largest element exceeds target
        sort(nums.begin(), nums.end());
        if (nums.back() > target) return false;

        int totalStates = 1 << n;
        // dp[mask] stores the current subset's accumulated sum modulo target, or -1 if invalid
        vector<int> dp(totalStates, -1);
        dp[0] = 0; // Base state: empty mask

        for (int mask = 0; mask < totalStates; mask++) {
            if (dp[mask] == -1) continue; // Unreachable state

            for (int i = 0; i < n; i++) {
                // Check if element i is not yet included in current mask
                if (!(mask & (1 << i))) {
                    // If adding nums[i] exceeds target sum, stop (since nums is sorted)
                    if (dp[mask] + nums[i] > target) break;

                    int nextMask = mask | (1 << i);
                    if (dp[nextMask] == -1) {
                        dp[nextMask] = (dp[mask] + nums[i]) % target;
                    }
                }
            }
        }

        return dp[totalStates - 1] != -1;
        
    }
};