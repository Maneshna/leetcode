class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int first=0; first<n; first++){
            for(int second = first +1; second<n;){
                int difference = abs(nums[first]-nums[second]);
                if(difference==k){
                    count++;
                }
                second++;
            }
        }
        return count;
    
        
    }
};