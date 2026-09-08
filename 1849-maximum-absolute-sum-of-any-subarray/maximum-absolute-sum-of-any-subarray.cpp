class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum =0;
        int currentMax =0;
        int minSum =0;
        int currentMin = 0;

        for(int num: nums){
            currentMax = max(currentMax+num, 0);
            maxSum = max(maxSum, currentMax);

            currentMin = min(0, currentMin+num);
            minSum = min(minSum, currentMin);
        }
        return max(abs(minSum), maxSum);
        
    }
};