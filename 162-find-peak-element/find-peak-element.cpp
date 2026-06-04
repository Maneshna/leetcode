class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If the element to the right is greater, 
            // then a peak must exist on the right half.
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } 
            // Otherwise, a peak must exist on the left half (including mid).
            else {
                right = mid;
            }
        }
        
        // 'left' and 'right' will converge to the peak element index
        return left;
    }
};