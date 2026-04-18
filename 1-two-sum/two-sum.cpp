class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>valWithIndex;
        int n=nums.size();
        for(int i =0;i<n;i++){
            valWithIndex.push_back({nums[i],i});
        }
        sort(valWithIndex.begin(), valWithIndex.end());

        
        int left=0;
        int right=n-1;

        while(left<right){
            int sum=valWithIndex[left].first +valWithIndex[right].first;
            if(sum == target){
                return{valWithIndex[left].second, valWithIndex[right].second};
            }
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
        return {};
        
    }
};