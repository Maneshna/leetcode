class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        //now we approach with the the optimal solution. since anything that says search, binary search can be applied so let's see. 
        //we can split the array in two. then work on the fact that the mid one might end up in the increasing side of the mountain. this way we will move to the right side. if not then left side.

        int n = nums.size();
        int low=0;
        int high=n-1;

        while(low<high){
            int mid = low+ (high - low)/2;

            if(nums[mid] < nums[mid+1]){
                //this means we are in the increasing side of the array so we move to the right side to find the peak

                low = mid +1;
            }
            else{
                //it means we are on the decreasing side of the array so we work on the left side instead

                high = mid;
            }
        }
        return low;

        
    }
};