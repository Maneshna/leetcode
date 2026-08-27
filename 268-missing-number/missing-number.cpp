class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();

        for(int i =0;i<nums.size(); i++){
            missing ^= i^nums[i]; //xor number from 0-n and the number from the array nums. the last remaning value will the missing number
        }
        return missing;
        
    }
};