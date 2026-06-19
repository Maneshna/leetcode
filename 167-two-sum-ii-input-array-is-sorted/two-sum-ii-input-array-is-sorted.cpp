class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //first and last will be defined. sum them if it is smaller than target then move first, if it is greater than the target, move the last to second last index and so on check. 


        int n = nums.size();
        int first = 0;
        int last = n-1;
        while(first<last){
            if(nums[first]+nums[last]==target){
                return {first+1,last+1};
            }
            else if(nums[first]+nums[last]>target){
                last--;
            }
            else if(nums[first]+nums[last]<target){
                first++;
            }
            
        }return{};
        
    }
};