class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            nums[i]=nums[i]*nums[i];


        }
        stable_sort(nums.begin(), nums.end());
        
        // 3. Return the sorted array
        return nums;
       
        
        
    }
};