class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int right = n-1;
        int left = 0;
        int index = n-1;

        while(left<=right){
            int leftsq = nums[left]*nums[left];
            int rightsq = nums[right]*nums[right];

            if(leftsq<=rightsq){
                result[index] = rightsq;
                right--;
            }
            else{
                result[index] = leftsq;
                left++;
            }
            index--;
        }
        return result;
        
        
    }
};