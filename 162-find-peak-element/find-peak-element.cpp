class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i<n;i++){

            bool greaterthanleft = ( i == 0 || nums[i]>nums[i-1]);

            bool greaterthanright = (i == n-1 || nums[i]>nums[i+1]);

            if(greaterthanleft && greaterthanright){
                return i;
            }
        }
        return 0;


        
    }
};