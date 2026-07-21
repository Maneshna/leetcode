class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> remainder_count(k,0);
        remainder_count[0]=1;

        int running_sum = 0;
        int total_subarrays = 0;

        for(int num: nums){
            running_sum += num;


            int remainder = (running_sum % k+k) %k;
            total_subarrays += remainder_count[remainder];
            remainder_count[remainder]++;
        }

        return total_subarrays;

        
    }
};