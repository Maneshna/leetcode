class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        long long ans=0;
        long long windowsum=0;
        int left =0;

        for(int right=0; right<nums.size(); right++){
            windowsum +=nums[right];
            freq[nums[right]]++;

            if(right-left+1>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);

                }
                windowsum-=nums[left];
                left++;
            }
            if(right-left+1==k && freq.size()==k){
                ans=max(ans,windowsum);
            }
            

        }return ans;
        
    }
};