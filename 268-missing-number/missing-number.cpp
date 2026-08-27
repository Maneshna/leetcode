class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n+1, false);
        for(int num: nums){
            seen[num] = true;
        }
        for(int i =0; i<=n;i++){
            if(!seen[i]){
                return i;
            }
        }
        return -1;
        
    }
};