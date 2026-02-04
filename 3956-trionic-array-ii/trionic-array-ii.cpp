class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return 0;

        const long long NEG = -1e18;
        vector<vector<long long>> dp(n, vector<long long>(3, NEG));

        for (int i = 1; i < n; i++) {
            // Phase 0: first increasing
            if (nums[i] > nums[i - 1]) {
                dp[i][0] = max(
                    dp[i - 1][0] + nums[i],
                    (long long)nums[i - 1] + nums[i]
                );
            }

            // Phase 1: decreasing
            if (nums[i] < nums[i - 1]) {
                if (dp[i - 1][0] != NEG)
                    dp[i][1] = max(dp[i][1], dp[i - 1][0] + nums[i]);
                if (dp[i - 1][1] != NEG)
                    dp[i][1] = max(dp[i][1], dp[i - 1][1] + nums[i]);
            }

            // Phase 2: second increasing
            if (nums[i] > nums[i - 1]) {
                if (dp[i - 1][1] != NEG)
                    dp[i][2] = max(dp[i][2], dp[i - 1][1] + nums[i]);
                if (dp[i - 1][2] != NEG)
                    dp[i][2] = max(dp[i][2], dp[i - 1][2] + nums[i]);
            }
        }

        long long ans = NEG;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i][2]);
        }

        return ans == NEG ? 0 : ans;
    }
};