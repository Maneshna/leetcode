class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n =nums.size();
        vector<pair<int, int>> numsWithIndex; // okay so these pairs are lik edictionray. first number will be the new number and the second number associated with it will the original original at those position after sorting
        for (int i = 0; i < n; i++) {
            numsWithIndex.push_back({nums[i], i});
        }
        sort(numsWithIndex.begin(), numsWithIndex.end());
        int left =0, right=n-1;
        while(left<right){
            int sum=numsWithIndex[left].first+numsWithIndex[right].first; //first as in the new index that we used after the array is sorted.
            if(sum==target){
                return {numsWithIndex[left].second, numsWithIndex[right].second};
            }
            else if(sum>target){
                right--;
            }
            else if(sum<target){
                left++;
            }

        
        }return {0};
        
    }
};