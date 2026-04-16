class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        int insertpos=0;



        for(int i = 0; i<n;i++){
            if(nums[i]!=0){
                nums[insertpos]=nums[i];
                insertpos++;

            }
        }
        while(insertpos<n){
            nums[insertpos]=0;
            insertpos++;
        }
        

        
    }
};