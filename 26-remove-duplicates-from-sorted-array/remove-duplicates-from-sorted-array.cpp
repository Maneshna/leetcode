class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()) return 0;

        int insertposition =1; //we will check from 2nd index to the one just before it so we skipped the index 0 aka 1st one
        for(int i =1; i<n; i++){
            if(nums[i] != nums[insertposition-1]){ //they are not same means they are unique so we replace the nums at the 
                nums[insertposition] = nums[i];
                insertposition++;
            }
        }
        return insertposition;
        
    }
};