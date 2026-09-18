class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //okay okay okay so first we start with multiplciation from left side in the array how? prefix sum. now for array [1,2,3,4] we begin with the first num. no prefix for this so just 1. now for the second number at num[1], the prefix is 1 so nums[1] is now 1. third number we have we have prefix as [1,2] so multiply them and the answer is 2. and for the fourth number it is 1*2*3=6. Now array is [1,1,2,6]
        int n = nums.size();
        vector<int> answer(n,1);

        int prefix =1;
        for(int i=0;i<n;i++){
            answer[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for(int i=n-1; i>=0; i--){
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        return answer;


        
    }
};