class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // first we try to sort every number to their own position. like 1 will be on position 1 and 3 on position 3 if we have -1 then it will fill all the lest over spaces. if not then last position mei daalo usko 

        int n =nums.size();
        for(int i=0; i<n; i++){
            while(nums[i]>=1 && nums[i]<=n && nums[nums[i]-1] != nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        //now we check the index and position at every position. there should be every number associated to each index. if missing i.e. some other random negative is filled then return the postion as the answer. 
        for(int i=0; i<n; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};