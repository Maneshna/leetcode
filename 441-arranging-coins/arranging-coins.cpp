class Solution {
public:
    int arrangeCoins(int n) {

        int low =0;
        int high = n;
        int ans =0;

        while(low<=high){
            long mid = low +(high-mid)/2;
            long coins = mid *(mid+1)/2;

            if(coins==n){
                return mid;
            }
            else if(coins<n){
                ans = mid;
                low = mid +1;
            }
            else{
                high = mid -1;
            }
        
        }return ans; 
        
    }
};