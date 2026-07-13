class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int insertposition = 1;
    int n = nums.size();


    for(int i =1; i<n; i++){
        if(nums[i]!= nums[insertposition-1]){
            nums[insertposition]= nums[i];
            insertposition++;
        }

    }
    return insertposition;
        
    }
};