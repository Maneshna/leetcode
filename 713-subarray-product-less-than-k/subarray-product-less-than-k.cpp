class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // nums and k diye hai. we need number of continuos subarrays
        // find product and then see if it is less than k or not. if yes then increase the number count by 1 if not then change the subarray sizes again 

        int n = nums.size();
        int left = 0;
        int current_product = 1;
        int count =0;


        if (k <= 1) return 0;

        //we will apply the sliding window concept in this.
        for(int right =0; right<n; right++){
            current_product = current_product*nums[right];

            while(current_product>= k){
                
                current_product /= nums[left];                
                left++;
            }
            count = count + (right-left +1);
        }
        return count;



        
    }
};