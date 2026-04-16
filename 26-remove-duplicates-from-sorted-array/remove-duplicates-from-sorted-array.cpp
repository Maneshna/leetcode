class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        int n = nums.size();
        int insertpos=1;
        for(int i=1; i<n;i++){
            if(nums[i] != nums[insertpos-1]){
                nums[insertpos]=nums[i];
                insertpos++;
            }

        }return insertpos;
        
    }
};