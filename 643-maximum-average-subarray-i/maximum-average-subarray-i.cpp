class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSum = 0;

        // sum of first window
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;

        // slide the window
        for (int i = k; i < n; i++) {
            windowSum += nums[i];        // add new
            windowSum -= nums[i - k];    // remove old
            maxSum = max(maxSum, windowSum);
        }

        return (double) maxSum / k;
    }
};