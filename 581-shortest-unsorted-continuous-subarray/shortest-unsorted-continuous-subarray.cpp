class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = -1;
        int end = -2; // Initialized so that if already sorted, end - start + 1 = 0
        
        int max_seen = nums[0];
        int min_seen = nums[n - 1];
        
        // Pass 1: Scan from left to right to find the rightmost out-of-order element
        for (int i = 1; i < n; i++) {
            max_seen = max(max_seen, nums[i]);
            if (nums[i] < max_seen) {
                end = i;
            }
        }
        
        // Pass 2: Scan from right to left to find the leftmost out-of-order element
        for (int i = n - 2; i >= 0; i--) {
            min_seen = min(min_seen, nums[i]);
            if (nums[i] > min_seen) {
                start = i;
            }
        }
        
        return end - start + 1;
    }
};