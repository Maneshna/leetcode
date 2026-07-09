class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //we will use the dynamic size of sliding window in this question. 
        int n = nums.size();
        int left = 0;
        int count = 0;

        for(int right = 0; right<n; right++){
            if(nums[right]==0){
                left = right + 1;
                
            }
            else{
                count=max(count, right-left+1);
            }
        }
        return count;
    }
};